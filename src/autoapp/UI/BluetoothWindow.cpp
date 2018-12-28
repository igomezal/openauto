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
    connect(ui_->pushButtonCancel, &QPushButton::clicked, this, &BluetoothWindow::close);
}

BluetoothWindow::~BluetoothWindow()
{
    delete ui_;
}

} // namespace ui
} // namespace autoapp
} // namespace openauto
} // namespace f1x
