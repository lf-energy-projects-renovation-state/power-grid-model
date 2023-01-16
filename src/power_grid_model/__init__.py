# SPDX-FileCopyrightText: 2022 Contributors to the Power Grid Model project <dynamic.grid.calculation@alliander.com>
#
# SPDX-License-Identifier: MPL-2.0

"""Power Grid Model"""

# pylint: disable=no-name-in-module

from power_grid_model.enum import (
    Branch3Side,
    BranchSide,
    CalculationMethod,
    CalculationType,
    LoadGenType,
    MeasuredTerminalType,
    WindingType,
)

from power_grid_model.power_grid_meta import power_grid_meta_data, initialize_array


# dummy PowerGridModel
class PowerGridModel:
    pass
