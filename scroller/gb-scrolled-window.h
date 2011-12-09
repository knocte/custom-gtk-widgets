/* gb-scrolled-window.h
 *
 * Copyright (C) 2011 Christian Hergert <chris@dronelabs.com>
 *
 * This file is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GB_SCROLLED_WINDOW_H
#define GB_SCROLLED_WINDOW_H

#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GB_TYPE_SCROLLED_WINDOW            (gb_scrolled_window_get_type())
#define GB_SCROLLED_WINDOW(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GB_TYPE_SCROLLED_WINDOW, GbScrolledWindow))
#define GB_SCROLLED_WINDOW_CONST(obj)      (G_TYPE_CHECK_INSTANCE_CAST ((obj), GB_TYPE_SCROLLED_WINDOW, GbScrolledWindow const))
#define GB_SCROLLED_WINDOW_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  GB_TYPE_SCROLLED_WINDOW, GbScrolledWindowClass))
#define GB_IS_SCROLLED_WINDOW(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GB_TYPE_SCROLLED_WINDOW))
#define GB_IS_SCROLLED_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  GB_TYPE_SCROLLED_WINDOW))
#define GB_SCROLLED_WINDOW_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  GB_TYPE_SCROLLED_WINDOW, GbScrolledWindowClass))

typedef struct _GbScrolledWindow        GbScrolledWindow;
typedef struct _GbScrolledWindowClass   GbScrolledWindowClass;
typedef struct _GbScrolledWindowPrivate GbScrolledWindowPrivate;

struct _GbScrolledWindow
{
   GtkEventBox parent;

   /*< private >*/
   GbScrolledWindowPrivate *priv;
};

struct _GbScrolledWindowClass
{
   GtkEventBoxClass parent_class;
};

GType gb_scrolled_window_get_type (void) G_GNUC_CONST;

G_END_DECLS

#endif /* GB_SCROLLED_WINDOW_H */
