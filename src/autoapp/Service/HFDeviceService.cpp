/*
*  This file is part of openauto project.
*  Copyright (C) 2018 f1x.studio (Michal Szwaj)
*
*  openauto is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 3 of the License, or
*  (at your option) any later version.

*  openauto is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with openauto. If not, see <http://www.gnu.org/licenses/>.
*/

#include <string>
#include <iostream>
#include <f1x/openauto/autoapp/Service/HFDeviceService.hpp>

namespace f1x
{
namespace openauto
{
namespace autoapp
{
namespace service
{

void HFDeviceService::getDevices(){
    std::string command = "get_devices.sh";
    std::string fullPath = this->bluetoothHelperPath + command;
    std::cout << fullPath << "\n";
    std::string devices = this->exec(fullPath.c_str());
    std::cout << "Hola" << devices << "Adios" << "\n";
}

void HFDeviceService::pair(){

}

void HFDeviceService::removeDevice(){

}

void HFDeviceService::connect(){

}

void HFDeviceService::disconnect(){

}

void HFDeviceService::info(){

}

void HFDeviceService::remove(){

}

std::string HFDeviceService::exec(char *cmd)
{
    FILE *pipe = popen(cmd, "r");
    if (!pipe)
        return "ERROR";
    char buffer[128];
    std::string result = "";
    while (!feof(pipe))
    {
        if (fgets(buffer, 128, pipe) != NULL)
            result += buffer;
    }
    pclose(pipe);
    return result;
}

} // namespace service
} // namespace autoapp
} // namespace openauto
} // namespace f1x
