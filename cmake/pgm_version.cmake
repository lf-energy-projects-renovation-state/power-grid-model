# SPDX-FileCopyrightText: Contributors to the Power Grid Model project <powergridmodel@lfenergy.org>
#
# SPDX-License-Identifier: MPL-2.0

cmake_minimum_required (VERSION 3.23)

file(READ "${CMAKE_CURRENT_SOURCE_DIR}/VERSION" _PGM_VERSION)
string(STRIP ${_PGM_VERSION} PGM_VERSION)
