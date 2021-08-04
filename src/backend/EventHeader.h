/* This file is part of the CARTA Image Viewer: https://github.com/CARTAvis/carta-backend
   Copyright 2018, 2019, 2020, 2021 Academia Sinica Institute of Astronomy and Astrophysics (ASIAA),
   Associated Universities, Inc. (AUI) and the Inter-University Institute for Data Intensive Astronomy (IDIA)
   SPDX-License-Identifier: GPL-3.0-or-later
*/

#include <stdint.h>

namespace carta {
const uint16_t ICD_VERSION = 23;
struct EventHeader {
    uint16_t type;
    uint16_t icd_version;
    uint32_t request_id;
};
} // namespace carta

