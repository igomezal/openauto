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
#include <map>
#include <vector>

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/range/algorithm/transform.hpp>
#include <boost/foreach.hpp>
#include <boost/bind.hpp>

#include <f1x/openauto/autoapp/Service/HFDeviceService.hpp>

namespace f1x
{
namespace openauto
{
namespace autoapp
{
namespace service
{

std::map<std::string, std::string> HFDeviceService::getDevices(){
    std::map <std::string, std::string> devices;

    std::string command = "get_devices.sh";
    std::string fullPath = this->bluetoothHelperPath + command;

    std::string devicesString = this->exec(fullPath.c_str());

    boost::trim(devicesString);

    std::vector<std::string> tokens;

    boost::split(tokens, devicesString, boost::is_any_of("\n"));

    std::for_each(tokens.begin(), tokens.end(),
        boost::bind(&boost::trim<std::string>,
            _1, std::locale()));

    BOOST_FOREACH(const std::string& i, tokens) {
        devices.insert(std::pair<std::string, std::string>(i.substr(0,17), i.substr(18)));
    }

    return devices;
}

std::string getDefaultDevice() {
    return "Test";
}

void HFDeviceService::pair(std::string bdAddr)
{
    std::string command = "pair.sh " + bdAddr;
    std::string fullPath = this->bluetoothHelperPath + command;
    std::string pairResult = this->exec(fullPath.c_str());

    std::cout << pairResult << std::endl;
}

void HFDeviceService::removeDevice(std::string bdAddr)
{
    std::string command = "remove.sh " + bdAddr;
    std::string fullPath = this->bluetoothHelperPath + command;
    std::string result = this->exec(fullPath.c_str());

    std::cout << result << std::endl;
}

void HFDeviceService::connect(std::string bdAddr)
{
    std::string command = "connect.sh " + bdAddr;
    std::string fullPath = this->bluetoothHelperPath + command;
    std::string result = this->exec(fullPath.c_str());

    std::cout << result << std::endl;
}

void HFDeviceService::disconnect(std::string bdAddr)
{
    std::string command = "disconnect.sh " + bdAddr;
    std::string fullPath = this->bluetoothHelperPath + command;
    std::string result = this->exec(fullPath.c_str());

    std::cout << result << std::endl;
}

void HFDeviceService::info(std::string bdAddr)
{
    std::string command = "info.sh " + bdAddr;
    std::string fullPath = this->bluetoothHelperPath + command;
    std::string result = this->exec(fullPath.c_str());

    std::cout << result << std::endl;
}

std::string HFDeviceService::exec(const char *cmd)
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
