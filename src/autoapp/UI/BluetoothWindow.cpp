#include <string>
#include <iostream>

#include <f1x/openauto/autoapp/UI/BluetoothWindow.hpp>
#include "ui_bluetoothwindow.h"

#include <f1x/openauto/autoapp/Service/HFDeviceService.hpp>

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
    ui_->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui_->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(ui_->pushButtonScan, &QPushButton::clicked, this, &BluetoothWindow::scanDevices);
    connect(ui_->pushButtonDisconnect, &QPushButton::clicked, this, &BluetoothWindow::disconnectDevice);
    connect(ui_->pushButtonCancel, &QPushButton::clicked, this, &BluetoothWindow::close);
    this->scanDevices();
}

BluetoothWindow::~BluetoothWindow()
{
    delete ui_;
}

void BluetoothWindow::scanDevices() {
    autoapp::service::HFDeviceService hfDeviceService;
    std::map<std::string, std::string> devices = hfDeviceService.getDevices();

    ui_->tableWidget->setRowCount(0);

    for(std::map<std::string, std::string>::iterator it=devices.begin(); it!=devices.end(); ++it) {
        int row = ui_->tableWidget->rowCount();
        ui_->tableWidget->insertRow(row);
        ui_->tableWidget->setItem(row, 0, new QTableWidgetItem());
        ui_->tableWidget->setItem(row, 1, new QTableWidgetItem());
        ui_->tableWidget->setItem(row, 2, new QTableWidgetItem());

        QTableWidgetItem *first = ui_->tableWidget->item(row, 0);
        QTableWidgetItem *second = ui_->tableWidget->item(row, 1);
        QTableWidgetItem *third = ui_->tableWidget->item(row, 2);

        QString fav = "*";
        QString name = QString::fromUtf8(it->second.c_str());
        QString bdAddr = QString::fromUtf8(it->first.c_str());

        if (first)
            first->setText(fav);
        if (second)
            second->setText(name);
        if (third)
            third->setText(bdAddr);
    }
}

void BluetoothWindow::disconnectDevice() {
    QModelIndexList selection = ui_->tableWidget->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);

    if(index.row() < 0 && index.row() > ui_->tableWidget->rowCount()) {
        return;
    }

    QTableWidgetItem* item = ui_->tableWidget->item(index.row(), 2);

    std::cout << item->text().toUtf8().constData() << std::endl;
}

} // namespace ui
} // namespace autoapp
} // namespace openauto
} // namespace f1x
