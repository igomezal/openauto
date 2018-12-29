#include <f1x/openauto/autoapp/UI/BluetoothWindow.hpp>
#include "ui_bluetoothwindow.h"

namespace f1x
{
namespace openauto
{
namespace autoapp
{
namespace ui
{

BluetoothWindow::BluetoothWindow(QWidget *parent)
    : QWidget(parent), ui_(new Ui::BluetoothWindow)
{
    ui_->setupUi(this);
    ui_->tableWidget->setColumnWidth(0, ui_->tableWidget->width()/3);
    ui_->tableWidget->setColumnWidth(1, ui_->tableWidget->width()/3);
    ui_->tableWidget->setColumnWidth(2, ui_->tableWidget->width()/3);
    ui_->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRow s);
    ui_->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(ui_->pushButtonCancel, &QPushButton::clicked, this, &BluetoothWindow::close);
    this->scanDevices();
    this->scanDevices();
}

BluetoothWindow::~BluetoothWindow()
{
    delete ui_;
}

void BluetoothWindow::scanDevices() {
    // Scan
    // Get Devices
    // Get Default Device
    // Add to the table

    int row = ui_->tableWidget->rowCount();
    ui_->tableWidget->insertRow(row);
    ui_->tableWidget->setItem(row, 0, new QTableWidgetItem());
    ui_->tableWidget->setItem(row, 1, new QTableWidgetItem());
    ui_->tableWidget->setItem(row, 2, new QTableWidgetItem());

    QString line = "*";
    QString name = "Iván";
    QString uuid = "78:45:33...";

    QTableWidgetItem *first = ui_->tableWidget->item(row,0);
    QTableWidgetItem *second = ui_->tableWidget->item(row, 1);
    QTableWidgetItem *third = ui_->tableWidget->item(row, 2);

    if(first)
        first->setText(line);
    if(second)
        second->setText(name);
    if(third)
        third->setText(uuid);
}

} // namespace ui
} // namespace autoapp
} // namespace openauto
} // namespace f1x
