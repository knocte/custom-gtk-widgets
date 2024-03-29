/* ppg-animation.h
 *
 * Copyright (C) 2010 Christian Hergert <chris@dronelabs.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PPG_ANIMATION_H
#define PPG_ANIMATION_H

#include <glib-object.h>

G_BEGIN_DECLS

#define PPG_TYPE_ANIMATION            (ppg_animation_get_type())
#define PPG_TYPE_ANIMATION_MODE       (ppg_animation_mode_get_type())
#define PPG_ANIMATION(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), PPG_TYPE_ANIMATION, PpgAnimation))
#define PPG_ANIMATION_CONST(obj)      (G_TYPE_CHECK_INSTANCE_CAST ((obj), PPG_TYPE_ANIMATION, PpgAnimation const))
#define PPG_ANIMATION_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  PPG_TYPE_ANIMATION, PpgAnimationClass))
#define PPG_IS_ANIMATION(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), PPG_TYPE_ANIMATION))
#define PPG_IS_ANIMATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  PPG_TYPE_ANIMATION))
#define PPG_ANIMATION_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  PPG_TYPE_ANIMATION, PpgAnimationClass))

typedef struct _PpgAnimation        PpgAnimation;
typedef struct _PpgAnimationClass   PpgAnimationClass;
typedef struct _PpgAnimationPrivate PpgAnimationPrivate;
typedef enum   _PpgAnimationMode    PpgAnimationMode;

enum _PpgAnimationMode
{
	PPG_ANIMATION_LINEAR,
	PPG_ANIMATION_EASE_IN_QUAD,
	PPG_ANIMATION_EASE_OUT_QUAD,
	PPG_ANIMATION_EASE_IN_OUT_QUAD,

	PPG_ANIMATION_LAST
};

struct _PpgAnimation
{
	GInitiallyUnowned parent;

	/*< private >*/
	PpgAnimationPrivate *priv;
};

struct _PpgAnimationClass
{
	GInitiallyUnownedClass parent_class;
};

GType ppg_animation_get_type        (void) G_GNUC_CONST;
GType ppg_animation_mode_get_type   (void) G_GNUC_CONST;
void  ppg_animation_start           (PpgAnimation *animation);
void  ppg_animation_stop            (PpgAnimation *animation);
void  ppg_animation_add_property    (PpgAnimation *animation,
                                     GParamSpec   *pspec,
                                     const GValue *value);
PpgAnimation* g_object_animate      (gpointer          object,
                                     PpgAnimationMode  mode,
                                     guint             duration_msec,
                                     const gchar      *first_property,
                                     ...) G_GNUC_NULL_TERMINATED;
PpgAnimation* g_object_animate_full (gpointer          object,
                                     PpgAnimationMode  mode,
                                     guint             duration_msec,
                                     guint             frame_rate,
                                     GDestroyNotify    notify,
                                     gpointer          notify_data,
                                     const gchar      *first_property,
                                     ...) G_GNUC_NULL_TERMINATED;

G_END_DECLS

#endif /* PPG_ANIMATION_H */
