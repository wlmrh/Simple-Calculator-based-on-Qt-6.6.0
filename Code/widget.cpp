#include "widget.h"
#include "./ui_widget.h"
#include "QTextStream"
#include "stack"
#include "string.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("汤琦 23020007110");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_one_clicked()
{
    exp += "1";
    ui->lineEdit->setText(exp);
}


void Widget::on_two_clicked()
{
    exp += "2";
    ui->lineEdit->setText(exp);
}


void Widget::on_three_clicked()
{
    exp += "3";
    ui->lineEdit->setText(exp);
}



void Widget::on_four_clicked()
{
    exp += "4";
    ui->lineEdit->setText(exp);
}


void Widget::on_five_clicked()
{
    exp += "5";
    ui->lineEdit->setText(exp);
}


void Widget::on_six_clicked()
{
    exp += "6";
    ui->lineEdit->setText(exp);
}


void Widget::on_seven_clicked()
{
    exp += "7";
    ui->lineEdit->setText(exp);
}


void Widget::on_eight_clicked()
{
    exp += "8";
    ui->lineEdit->setText(exp);
}


void Widget::on_nine_clicked()
{
    exp += "9";
    ui->lineEdit->setText(exp);
}


void Widget::on_zero_clicked()
{
    exp += "0";
    ui->lineEdit->setText(exp);
}


void Widget::on_left_clicked()
{
    exp += "(";
    ui->lineEdit->setText(exp);
}


void Widget::on_right_clicked()
{
    exp += ")";
    ui->lineEdit->setText(exp);
}


void Widget::on_plus_clicked()
{
    exp += "+";
    ui->lineEdit->setText(exp);
}


void Widget::on_sub_clicked()
{
    exp += "-";
    ui->lineEdit->setText(exp);
}


void Widget::on_mult_clicked()
{
    exp += "x";
    ui->lineEdit->setText(exp);
}


void Widget::on_div_clicked()
{
    exp += "/";
    ui->lineEdit->setText(exp);
}


void Widget::on_point_clicked()
{
    exp += ".";
    ui->lineEdit->setText(exp);
}


void Widget::on_back_clicked()
{
    exp.chop(1);
    ui->lineEdit->setText(exp);
}


void Widget::on_equ_clicked()
{
    exp += '=';
    std::stack<double> num; std::stack<char> sign;std::string str = exp.toStdString(); double value = -999999, level = 0;
    int isminus = 0, isdivider = 0, ismult = 0; double crt = 1, divider = 1;//isminus判断是否为负数
    for(int i = 0; i < str.length(); i++){
        //读取一个完整的数字,存放在value中
        while((str[i] <= '9' && str[i] >= '0') || str[i] == '.'){
            if(str[i] >= '0' && str[i] <= '9'){
                if(value == -999999) {value = str[i++] - '0'; continue;}
                if(level == 0) value = value * 10 + str[i++] - '0';
                if(level != 0) {value += (str[i++] - '0') * pow(10, -level); level++;}
            }
            else{
                level = 1;
                i++;
            }
        }
        //存储数据数据并初始化
        if(value != -999999 && isminus == 1) num.push((-1) * value);
        else if(value != -999999 && ismult == 1) num.push(value * crt);
        else if(value != -999999 && isdivider == 1) num.push(divider / value);
        else{
            if(value != -999999) num.push(value);
        }
        value = -999999; level = 0; crt = 1; divider = 1; isminus = 0; isdivider = 0; ismult = 0;
        if(str[i] == '='){
            break;
        }
        //判断下一个符号
        if(str[i] == '-') {isminus = 1; continue;}
        if(str[i] == 'x'){
            ismult = 1;
            crt = num.top();
            num.pop();
            continue;
        }
        if(str[i] == '/'){
            isdivider = 1;
            divider = num.top();
            num.pop();
        }
    }
    double rst = 0;
    while(num.empty() == 0){
        rst += num.top();
        num.pop();
    }
    //结果显示，并将其作为新表达式的开头
    exp.clear();
    ui->lineEdit->setText(QString::number(rst));
    exp.clear();
    exp.append(QString::number(rst));
}

void Widget::on_pushButton_clicked()
{
    exp.clear();
    ui->lineEdit->setText(exp);
}

