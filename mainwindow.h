#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGraphicsGridLayout>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtCharts/QLineSeries>
#include <QtCharts/QScatterSeries>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
QT_CHARTS_USE_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void addSeries(int start, int end, int kk); // line
    void addScatter(int start, int end, int kk); // scatter
    void removeSeries();
    void removeScatter();
    void connectMarkers();
    void disconnectMarkers();
    void handleMarkerClicked();


    void on_toolButton_clicked();

    void on_pushButton_v_clicked();

    void on_toolButton_2_clicked();

private:
    Ui::MainWindow *ui;

    QChart *m_chart;
    QList<QLineSeries *> m_series;
    QList<QScatterSeries *> m_series_s;

    QChartView *m_chartView;
    QGridLayout *m_mainLayout;
    QGridLayout *m_fontLayout;
};
#endif // MAINWINDOW_H
