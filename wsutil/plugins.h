/* plugins.h
 * definitions for plugins structures
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
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
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __PLUGINS_H__
#define __PLUGINS_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <glib.h>
#include <gmodule.h>

#include "ws_symbol_export.h"

typedef gboolean (*plugin_check_type_callback)(GModule *handle);

typedef enum {
    REPORT_LOAD_FAILURE,
    DONT_REPORT_LOAD_FAILURE
} plugin_load_failure_mode;
WS_DLL_PUBLIC void scan_plugins(plugin_load_failure_mode mode);
WS_DLL_PUBLIC void add_plugin_type(const char *type, plugin_check_type_callback callback);
typedef void (*plugin_description_callback)(const char *name, const char *version,
                                            const char *types, const char *filename,
                                            void *user_data);
WS_DLL_PUBLIC void plugins_get_descriptions(plugin_description_callback callback, void *user_data);
WS_DLL_PUBLIC void plugins_dump_all(void);
WS_DLL_PUBLIC int plugins_get_count(void);
WS_DLL_PUBLIC void plugins_cleanup(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __PLUGINS_H__ */

/*
 * Editor modelines
 *
 * Local Variables:
 * c-basic-offset: 4
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * ex: set shiftwidth=4 tabstop=8 expandtab:
 * :indentSize=4:tabSize=8:noTabs=true:
 */
