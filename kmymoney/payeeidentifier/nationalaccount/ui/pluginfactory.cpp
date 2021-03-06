/*
 * This file is part of KMyMoney, A Personal Finance Manager for KDE
 * Copyright (C) 2014  Christian David <christian-david@web.de>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <KPluginFactory>

#include "nationalaccountdelegate.h"

K_PLUGIN_FACTORY(ibanAndBicPidWidgetsFactory,
                 registerPlugin<nationalAccountDelegate>("delegate");
                )
K_EXPORT_PLUGIN(ibanAndBicPidWidgetsFactory("payeeidentifier_nationalaccount_ui"))
