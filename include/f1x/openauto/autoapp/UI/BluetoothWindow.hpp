#pragma once

#include <QWidget>

namespace Ui
{
class BluetoothWindow;
}

namespace f1x
{
namespace openauto
{
namespace autoapp
{
namespace ui
{

class BluetoothWindow : public QWidget
{
    Q_OBJECT

  public:
    explicit BluetoothWindow(QWidget *parent = nullptr);
    ~BluetoothWindow() override;

  private:
    void scanDevices();
    void disconnectDevice();
    void connectDevice();
    void setDefaultDevice();
    void removeDevice();

    Ui::BluetoothWindow *ui_;
};

} // namespace ui
} // namespace autoapp
} // namespace openauto
} // namespace f1x
