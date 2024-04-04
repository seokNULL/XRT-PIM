// SPDX-License-Identifier: Apache-2.0
// Copyright (C) 2022-2023 Advanced Micro Devices, Inc. All rights reserved.

#ifndef _XCL_PCIDRV_XDMA_H_
#define _XCL_PCIDRV_XDMA_H_

#include "pcidrv.h"
#include <string>

namespace xrt_core { namespace pci {

class drv_xdma : public drv
{
public:
  std::string
  name() const override { return "xdma"; }

  bool
  is_user() const override { return true; }

  std::string
  dev_node_prefix() const override { return name(); }

  std::string
  dev_node_dir() const override { return ""; }

  std::string
  sysfs_dev_node_dir() const override { return ""; }
};

} } // namespace xrt_core :: pci

#endif
