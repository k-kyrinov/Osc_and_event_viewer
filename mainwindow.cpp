#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCharts>

#include "chart.h"
#include "chartview.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCore/QtMath>
#include <QtCore/QRandomGenerator>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <QtCharts/QLegend>
#include <QtCharts/QValueAxis>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <QtCore/QDebug>
#include <QtCharts/QLegend>
#include <QtWidgets/QFormLayout>
#include <QtCharts/QLegendMarker>
#include <QtCharts/QLineSeries>
#include <QtCharts/QXYLegendMarker>
#include <QtCore/QtMath>
#include <QtGui/QPainter>
#include <QtWidgets/QGraphicsTextItem>
#include <numeric>

QT_CHARTS_USE_NAMESPACE

std::vector<int> ints;
std::vector<int> y_c;
std::vector<int> xx;
std::vector<int> yy;
std::vector<int> size_ev;
std::vector<int> e_n_temp;

double x_det[16] = {-7.5, -2.5, 2.5, 7.5, -7.5,-2.5,2.5,7.5,-7.5,-2.5,2.5,7.5,-7.5,-2.5,2.5,7.5};
double y_det[16] = {7.5, 7.5,7.5,7.5, 2.5, 2.5,2.5,2.5, -2.5, -2.5,-2.5,-2.5, -7.5, -7.5,-7.5,-7.5};
double s[16] = {1, 2,3,10, 12, 20,1,2, 2, 4,5,-5, 7, 7,10,12};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize ( 781, 453 );
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::addSeries(int start, int end, int kk)
{
    QLineSeries *series = new QLineSeries();
    m_series.append(series);
    series->setName(QString("det_" + QString::number(m_series.count())));

    int j{};
    if(ui->radioButton_inr->isChecked()){
    for (int i = 0; i < 164500; ++i){
        series->append(i*32e-3, ints[j+kk]);
        j+=16;
        }
    }

    else if(ui->radioButton_ybj->isChecked()){
        j=start*16;
        for (int i = start; i < end; ++i){
            if((xx[j+kk]!=0 and yy[j+kk]!=0)) series->append(xx[j+kk]*1e-3,yy[j+kk]*2);
            if( std::abs(xx[j+kk+16] - xx[j+kk]) > 20 and xx[j+kk+16]!=0) series->append((xx[j+kk]+20)*1e-3, 0);
            series->setName(QString::number(kk+1) + "_det");
            j+=16;
        }
    }


    //if(kk<5)series->setVisible(false);
    //series->append(data);
    m_chart->addSeries(series);

//    if (m_series.count() == 1)
//        m_chart->createDefaultAxes();
}

void MainWindow::addScatter(int start, int end, int kk)
{

    QScatterSeries *series = new QScatterSeries(); //QLineSeries *series = new QLineSeries();
    m_series_s.append(series);

    series->setName(QString("det_" + QString::number(m_series_s.count())));

    int j{};
    if(ui->radioButton_inr->isChecked()){
    for (int i = 0; i < 164500; ++i){
        if(ints[j+kk]> 2) series->append(i*32e-3, ints[j+kk]);
        j+=16;
        }
    }
    else if(ui->radioButton_ybj->isChecked()){
        j=start*16;
        for (int i = start; i < end; ++i){
            if(yy[j+kk]> 2) series->append(xx[j+kk]*1e-3, yy[j+kk]*2); // mcs
            series->setName(QString::number(kk+1) + "_det");
            j+=16;
        }
    }
    //if(kk<5)series->setVisible(false);
    //series->append(data);
    series->setMarkerSize(10); // 10
    series->setBorderColor(Qt::transparent);
    m_chart->addSeries(series);

//    if (m_series.count() == 1)
//        m_chart->createDefaultAxes();
}

void MainWindow::removeSeries()
{
    // Remove last series from chart
    if (m_series.count() > 0) {
        QLineSeries *series = m_series.last();
        m_chart->removeSeries(series);
        m_series.removeLast();
        delete series;
    }
}

void MainWindow::removeScatter()
{
    // Remove last series from chart
    if (m_series_s.count() > 0) {
        QScatterSeries *series = m_series_s.last();
        m_chart->removeSeries(series);
        m_series.removeLast();
        delete series;
    }
}

void MainWindow::connectMarkers()
{
//![1]
    // Connect all markers to handler
    const auto markers = m_chart->legend()->markers();
    for (QLegendMarker *marker : markers) {
        // Disconnect possible existing connection to avoid multiple connections
        QObject::disconnect(marker, &QLegendMarker::clicked,
                            this, &MainWindow::handleMarkerClicked);
        QObject::connect(marker, &QLegendMarker::clicked, this, &MainWindow::handleMarkerClicked);
    }
//![1]
}

void MainWindow::disconnectMarkers()
{
//![2]
    const auto markers = m_chart->legend()->markers();
    for (QLegendMarker *marker : markers) {
        QObject::disconnect(marker, &QLegendMarker::clicked,
                            this, &MainWindow::handleMarkerClicked);
    }
//![2]
}

void MainWindow::handleMarkerClicked()
{
//![3]
    QLegendMarker* marker = qobject_cast<QLegendMarker*> (sender());
    Q_ASSERT(marker);
//![3]

//![4]
    switch (marker->type())
//![4]
    {
        case QLegendMarker::LegendMarkerTypeXY:
        {
//![5]
        // Toggle visibility of series
        marker->series()->setVisible(!marker->series()->isVisible());

        // Turn legend marker back to visible, since hiding series also hides the marker
        // and we don't want it to happen now.
        marker->setVisible(true);
//![5]

//![6]
        // Dim the marker, if series is not visible
        qreal alpha = 1.0;

        if (!marker->series()->isVisible())
            alpha = 0.5;

        QColor color;
        QBrush brush = marker->labelBrush();
        color = brush.color();
        color.setAlphaF(alpha);
        brush.setColor(color);
        marker->setLabelBrush(brush);

        brush = marker->brush();
        color = brush.color();
        color.setAlphaF(alpha);
        brush.setColor(color);
        marker->setBrush(brush);

        QPen pen = marker->pen();
        color = pen.color();
        color.setAlphaF(alpha);
        pen.setColor(color);
        marker->setPen(pen);

//![6]
        break;
        }
    default:
        {
        qDebug() << "Unknown marker type";
        break;
        }
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ints.size()==0 and xx.size()==0)
    {
        QMessageBox msgWarning;
        msgWarning.setText("WARNING!\nPlease choose osc. file.");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Caution");
        msgWarning.exec();
    }
    else{
    QWidget *wdg = new QWidget;
    wdg->show();
    m_chart = new Chart();
    m_chartView = new ChartView(m_chart, wdg);
    m_mainLayout = new QGridLayout(wdg);
    m_mainLayout->addWidget(m_chartView, 0, 1, 3, 1);
    setLayout(m_mainLayout);

    int ss = ui->comboBox->currentIndex();
    int left{};
    if(ui->radioButton_ybj->isChecked()){
        for (int j = ss; j > 0 ; --j) left+=size_ev[j];
    }

    for(int kk = 0; kk < 16; ++kk){
        if(ui->radioButton_inr->isChecked()) (ui->radioButton_fast->isChecked())? addScatter(0,0, kk): addSeries(0,0, kk);
        else if (ui->radioButton_ybj->isChecked()){
         if(ss==0) (ui->radioButton_fast->isChecked())? addScatter(0, size_ev[0], kk): addSeries(0, size_ev[0], kk);
         else (ui->radioButton_fast->isChecked())? addScatter(left-size_ev[ss], left, kk): addSeries(left-size_ev[ss], left, kk);
        }
    }

    connectMarkers();
    m_chart->setTitle(ui->lineEdit_file1->text());
    m_chart->legend()->setVisible(true);
    m_chart->legend()->setAlignment(Qt::AlignBottom);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    m_chart->createDefaultAxes();
    QFont labelsFont;
    labelsFont.setPixelSize(35);
    m_chart->axisX()->setLabelsFont(labelsFont);
    m_chart->axisY()->setLabelsFont(labelsFont);
    m_chart->axisX()->setTitleFont(labelsFont);
    m_chart->axisY()->setTitleFont(labelsFont);
    //axisY->setLabelsFont(labelsFont);
    m_chart->axisY()->setTitleText("Amp, ACD");
    m_chart->axisX()->setTitleText("Time, μs");
    }
}

void MainWindow::on_toolButton_clicked()
{
    QStringList file = QFileDialog::getOpenFileNames(this, "Select a file to open...", QDir::homePath());
    ui->lineEdit_file1->setText(file[0]);
    if(ui->radioButton_inr->isChecked()){           // format ENDA-INR
        QString pat = ui->lineEdit_file1->text();
        std::string str = pat.toStdString();
        str.c_str();
        std::fstream f(str);

        std::string line;
        std::vector<std::string> parsedRow2;
        while(std::getline(f,line))
        {
            std::stringstream lineStream(line);
            std::string cell;
            std::vector<std::string> parsedRow;
            while(std::getline(lineStream,cell, ' ') ) parsedRow.push_back(cell);
            for(int i = 1; i < 33; i+=2)
            (ui->radioButton_d5->isChecked())? parsedRow2.push_back(parsedRow[i+1]): parsedRow2.push_back(parsedRow[i]);
        }
        std::transform(parsedRow2.begin(), parsedRow2.end(), std::back_inserter(ints),
                [&](std::string s) {
                    return stoi(s);
                });
    }

    std::ofstream test("C:\\Qt\\progects\\ENDA_YBJ\\test.txt");
    std::ofstream test1("C:\\Qt\\progects\\ENDA_YBJ\\test1.txt");
    // ENDA - YBJ
    bool flag = 1;
    if(ui->radioButton_ybj->isChecked()){
        QString pat = ui->lineEdit_file1->text();
        std::string str = pat.toStdString();
        str.c_str();
        std::fstream f(str);

        std::string line;
        std::vector<std::string> parsedRow2;
        int ss{};
        while(std::getline(f,line))
        {
            std::stringstream lineStream(line);
            std::string cell;
            std::vector<std::string> parsedRow;
            while(std::getline(lineStream,cell, ' ') ) parsedRow.push_back(cell);
            if(parsedRow.size()==3 and std::stoi(parsedRow[1]) > ui->spinBox->value()){
               flag = 1;
               ui->comboBox->addItem(QString("event_") + QString::fromStdString(parsedRow[0]) + "-" + QString::fromStdString(parsedRow[1]) + QString("_neutrons"));
               }
            else if((parsedRow.size()==3 and std::stoi(parsedRow[1]) < ui->spinBox->value()) /*or (parsedRow.size()==1)*/ ){
               flag = 0;
            }
            else if(parsedRow.size()>3 and flag==1){
               ss+=1;
               for(int i = 0; i < 64; i+=2){
                   //x_c.push_back(parsedRow[i]);
                   y_c.push_back(std::stoi(parsedRow[i+1]));
                }
             }
            else if(parsedRow.size()==1 and flag==1){
                flag = 0;
                size_ev.push_back(ss);
                ss = 0;
            }
        }
//        std::ifstream ff("C:\\Qt\\progects\\ENDA_YBJ\\t.txt");
//        int a,b;
//        while (ff>> a and ff >> b){
//            xx.push_back(a);
//            yy.push_back(b);
//        }

        for (int i = 0; i < y_c.size(); i+=2) {
            xx.push_back(y_c[i]);
            yy.push_back(y_c[i+1]);
        }

        for (int i = 0; i < xx.size() ; ++i) {
            if (i%16==0 and i!=0) test1 << '\n';
            if (i%32 ==0 and i!=0) test << '\n';
            test << y_c[i] << ' ' /*<< y_c[i]*/;
            test1 << xx[i] << ' ' << yy[i] << ' ';
        }
        //for(int i = 0; i < size_ev.size(); ++i) test1 << size_ev[i] << ' ';
    }

    qDebug() << size_ev.size() << '\n';
    //qDebug() << ints.size() << '\n';
    qDebug() << y_c.size() << ' ' << xx.size() << ' ' << yy.size() << '\n';

    //qDebug() << file.size() << '\n';
}

void MainWindow::on_toolButton_2_clicked()
{
    QStringList file2 = QFileDialog::getOpenFileNames(this, "Select a file to open...", QDir::homePath());
    ui->lineEdit->setText(file2[0]);
    QString pat = ui->lineEdit->text();
    std::string str = pat.toStdString();
    str.c_str();
    std::fstream f(str);
    std::string line;
    std::vector<std::string> parsedRow2;
    while(std::getline(f,line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<std::string> parsedRow;
        while(std::getline(lineStream,cell, ' ') ) parsedRow.push_back(cell);
        if(std::stoi(parsedRow[5]) > ui->spinBox->value()){
        ui->comboBox_2->addItem(QString("event_") + QString::fromStdString(parsedRow[0]) + "-" + QString::fromStdString(parsedRow[5]) + QString("_neutrons"));
        for(int i = 7; i < 54; i+=3){
        if(ui->radioButton_d8->isChecked()){
            parsedRow2.push_back(parsedRow[i]);
            //parsedRow2.push_back(parsedRow[i+2]);
        }
        else if(ui->radioButton_d5->isChecked()){
            parsedRow2.push_back(parsedRow[i+1]);
            //parsedRow2.push_back(parsedRow[i+2]);
        }
    }
        for(int i = 7; i < 54; i+=3){
        if(ui->radioButton_d8->isChecked()){
            //parsedRow2.push_back(parsedRow[i]);
            parsedRow2.push_back(parsedRow[i+2]);
        }
        else if(ui->radioButton_d5->isChecked()){
            //parsedRow2.push_back(parsedRow[i+1]);
            parsedRow2.push_back(parsedRow[i+2]);
        }
    }

   }
        else qDebug() << std::stoi(parsedRow[6]) << '\n';
       //(ui->radioButton_d5->isChecked())? parsedRow2.push_back(parsedRow[i+1]): parsedRow2.push_back(parsedRow[i]);
    }
    std::transform(parsedRow2.begin(), parsedRow2.end(), std::back_inserter(e_n_temp),
            [&](std::string s) {
                return stoi(s);
            });

//    while (f >> number) e_n.push_back(number);
      qDebug() << e_n_temp.size() << '\n';

}

void MainWindow::on_pushButton_v_clicked()
{
    int ss = ui->comboBox_2->currentIndex();
    std::vector<int> e_n;
    qDebug() << e_n_temp.size() << ' ' << e_n.size() << '\n';
    //e_n.erase (e_n.begin(), e_n.begin()+3);
   // e_n = e_n_temp;
//    if(e_n.size()>32 and ss == 0) e_n.erase (e_n.begin()+32, e_n.end());
//    else if(e_n.size()>32 and ss != 0){
//        e_n.erase (e_n.begin(), e_n.begin()+ss*32);
//        e_n.erase (e_n.begin()+(ss+1)*32, e_n.end());
//    }
    for (int i= ss*32; i < (ss+1)*32; ++i) {
        e_n.push_back(e_n_temp[i]);
    }
    qDebug() << e_n.size() << '\n';

    if(e_n.size()==0)
    {
        QMessageBox msgWarning;
        msgWarning.setText("WARNING!\nPlease choose eas. file.");
        msgWarning.setIcon(QMessageBox::Warning);
        msgWarning.setWindowTitle("Caution");
        msgWarning.exec();
    }
    else{

    QWidget *wdg = new QWidget;
    wdg->setFixedSize(800,800);
    wdg->show();

//    std::ifstream input("C:\\Qt\\progects\\ENDA_YBJ\\eas_test.txt");
//    double *ed = new double[32];
//    for (int i = 0; i < 32; ++i ) {
//        input >> ed[i];
//    }

    QChart *chart = new QChart;
    m_chartView = new QChartView(chart, wdg);
    m_mainLayout = new QGridLayout(wdg);
    m_mainLayout->addWidget(m_chartView, 0, 1, 3, 1);
    setLayout(m_mainLayout);

    if(ui->radioButton_ta->isChecked()){                // TA
    auto max_it = std::max_element(e_n.begin()+16, e_n.end());
    //qDebug() << *max_it << '\n';
    for(int k = 0; k < 16; ++k){
    QScatterSeries *series = new QScatterSeries();
    series->append(x_det[k], y_det[k]);
    series->setMarkerSize(35.0*static_cast<float>(e_n[k+16])/(*max_it)+5);
    //qDebug() << (25.0*std::log10(static_cast<float>(e_n[16+k])/(*max_it)+1)) << '\n';
    series->setColor(QColor(0, 4, 255, 255));
    series->setBorderColor(Qt::transparent);
    chart->addSeries(series);
    }
 }
    else{

        QScatterSeries *series = new QScatterSeries();
        for(int k = 0; k < 16; ++k){
        series->append(x_det[k], y_det[k]);
        }
        series->setMarkerSize(25);
        series->setColor(QColor(0, 4, 255, 255));
        series->setBorderColor(Qt::transparent);
        chart->addSeries(series);
        }

    int start_x = 150, start_y = 150;
    for (int k = 0; k < 16; ++k ) {
        if(k%4==0 and k!=0){
            start_x = 250;
            start_y +=110;
            QGraphicsSimpleTextItem *m_coordX = new QGraphicsSimpleTextItem(chart);
            m_coordX->setPos(start_x, start_y);
            m_coordX->setText("e: " +QString::number(e_n[k]));
            m_coordX->setBrush(Qt::magenta);
            m_coordX->setScale(1.55);
        }
        else{
        start_x +=100;
        QGraphicsSimpleTextItem *m_coordX = new QGraphicsSimpleTextItem(chart);
        m_coordX->setPos(start_x, start_y);
        m_coordX->setText("e: " + QString::number(e_n[k]));
        m_coordX->setBrush(Qt::magenta);
        m_coordX->setScale(1.55);
        }
    }

    start_x = 150, start_y = 220;
    for (int k = 0; k < 16; ++k ) {
        if(k%4==0 and k!=0){
            start_x = 250;
            start_y +=110;
            QGraphicsSimpleTextItem *m_coordX = new QGraphicsSimpleTextItem(chart);
            m_coordX->setPos(start_x, start_y);
            m_coordX->setText("n: " +QString::number(e_n[k+16]));
            m_coordX->setBrush(Qt::blue);
            m_coordX->setScale(1.55);
        }
        else{
        start_x +=100;
        QGraphicsSimpleTextItem *m_coordX = new QGraphicsSimpleTextItem(chart);
        m_coordX->setPos(start_x, start_y);
        m_coordX->setText("n: " +QString::number(e_n[k+16]));
        m_coordX->setBrush(Qt::blue);
        m_coordX->setScale(1.55);
        }
    }

    QGraphicsSimpleTextItem *m_coordX = new QGraphicsSimpleTextItem(chart);
    m_coordX->setPos(120, 75);
    m_coordX->setText("Nsum: " + QString::number(std::accumulate(e_n.begin()+16, e_n.end(), 0)));
    m_coordX->setBrush(Qt::red);
    m_coordX->setScale(2.0);


//    QGraphicsSimpleTextItem *m_coordX = new QGraphicsSimpleTextItem(chart);
//    m_coordX->setPos(240, 150);
//    m_coordX->setText(QString::number(e_n[0]));


    chart->createDefaultAxes();
    QFont labelsFont;
    labelsFont.setPixelSize(18);
    //chart->setTitle(QString::number(std::accumulate(e_n.begin()+16, e_n.end(), 0)));
    chart->axisX()->setLabelsFont(labelsFont);
    chart->axisY()->setLabelsFont(labelsFont);
    chart->axisX()->setTitleFont(labelsFont);
    chart->axisY()->setTitleFont(labelsFont);
    //axisY->setLabelsFont(labelsFont);
    chart->axisY()->setTitleText("Y, m");
    chart->axisX()->setTitleText("X, m");
    chart->legend()->hide();
    chart->axes(Qt::Vertical).first()->setRange(-15,15);
    chart->axes(Qt::Horizontal).first()->setRange(-15,15);
    }
}


