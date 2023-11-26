#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_one_clicked();

    void on_two_clicked();

    void on_three_clicked();

    void on_four_clicked();

    void on_five_clicked();

    void on_six_clicked();

    void on_seven_clicked();

    void on_eight_clicked();

    void on_nine_clicked();

    void on_zero_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_plus_clicked();

    void on_sub_clicked();

    void on_mult_clicked();

    void on_div_clicked();

    void on_point_clicked();

    void on_back_clicked();

    void on_equ_clicked();

    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    QString exp;
};
#endif // WIDGET_H
