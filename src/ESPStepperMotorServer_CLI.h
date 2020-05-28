//      ******************************************************************
//      *                                                                *
//      *       Header file for ESPStepperMotorServer_CLI.cpp            *
//      *                                                                *
//      *               Copyright (c) Paul Kerspe, 2019                  *
//      *                                                                *
//      ******************************************************************

// MIT License
//
// Copyright (c) 2019 Paul Kerspe
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is furnished
// to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef ESPStepperMotorServer_CLI_h
#define ESPStepperMotorServer_CLI_h

#define MAX_CLI_CMD_COUNTER 30

#include <Arduino.h>
#include <ESPStepperMotorServer_Logger.h>

class ESPStepperMotorServer_CLI
{
public:
  ESPStepperMotorServer_CLI();
  static void processSerialInput(void *parameter);
  void executeCommand(String cmd);
  void start();
  void stop();
  void cmdHelp(String args);
  void cmdReboot(String args);
  void cmdSwitchStatus(String args);

private:
  void registerCommands();
  void registerNewCommand(const char cmd[], const char description[], void (ESPStepperMotorServer_CLI::*f)(String));
  bool started;
  TaskHandle_t xHandle = NULL;
  void (ESPStepperMotorServer_CLI::*command_functions[MAX_CLI_CMD_COUNTER + 1])(String);
  const char *command_details[MAX_CLI_CMD_COUNTER +1 ][2];
  unsigned int commandCounter = 0;
};

#endif