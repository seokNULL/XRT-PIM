/**
 * Copyright (C) 2016-2020 Xilinx, Inc
 * Copyright (C) 2023 Advanced Micro Devices, Inc. - All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You may
 * not use this file except in compliance with the License. A copy of the
 * License is located at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

#define XDP_PLUGIN_SOURCE

#include "xocl/core/platform.h"
#include "xocl/core/device.h"

#include "xdp/profile/plugin/device_offload/opencl/opencl_device_info_cb.h"
#include "xdp/profile/plugin/device_offload/opencl/opencl_device_info_plugin.h"
#include "xdp/profile/plugin/vp_base/utility.h"

namespace xdp {
  static OpenCLDeviceInfoPlugin deviceInfoPluginInstance ;

  // This function gets called in a callback at the OpenCL layer.
  //  It could be either hardware or hardware emulation.  In either case,
  //  we call the same higher level function.
  static void updateDeviceOpenCL(xrt_xocl::device* handle)
  {
    deviceInfoPluginInstance.updateDevice(handle) ;
  }

  static void flushDeviceOpenCL(xrt_xocl::device* handle)
  {
    deviceInfoPluginInstance.flushDevice(handle) ;
  }

} // end namespace xdp 


extern "C"
void updateDeviceOpenCL(void* handle)
{
  xdp::updateDeviceOpenCL(static_cast<xrt_xocl::device*>(handle)) ;
}

extern "C"
void flushDeviceOpenCL(void* handle)
{
  xdp::flushDeviceOpenCL(static_cast<xrt_xocl::device*>(handle)) ;
}
