#ifndef FLUTTER_PLUGIN_HARDWARE_SIMULATOR_PLUGIN_H_
#define FLUTTER_PLUGIN_HARDWARE_SIMULATOR_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>
#include <thread>

namespace hardware_simulator {

class HardwareSimulatorPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  HardwareSimulatorPlugin();

  virtual ~HardwareSimulatorPlugin();

  // Disallow copy and assign.
  HardwareSimulatorPlugin(const HardwareSimulatorPlugin&) = delete;
  HardwareSimulatorPlugin& operator=(const HardwareSimulatorPlugin&) = delete;

  void StartMonitorThread();
  void StopMonitorThread();

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);

 private:
  std::unique_ptr<flutter::MethodChannel<flutter::EncodableValue>> channel_;
  std::unique_ptr<std::thread> monitor_thread_;
};

}  // namespace hardware_simulator

#endif  // FLUTTER_PLUGIN_HARDWARE_SIMULATOR_PLUGIN_H_
