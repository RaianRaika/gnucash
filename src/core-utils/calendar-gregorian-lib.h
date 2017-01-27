/*********************************************************************\
 * calendar-gregorian-lib.h -- Gregorian implimention of Calendar-lib *
 * Copyright 2016 Amin Aghabiki <amin[dot]aghabeiki[at]gmail.com>     *
 *                                                                    *
 * This program is free software; you can redistribute it and/or      *
 * modify it under the terms of the GNU General Public License as     *
 * published by the Free Software Foundation; either version 2 of     *
 * the License, or (at your option) any later version.                *
 *                                                                    *
 * This program is distributed in the hope that it will be useful,    *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of     *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the      *
 * GNU General Public License for more details.                       *
 *                                                                    *
 * You should have received a copy of the GNU General Public License  *
 * along with this program; if not, contact:                          *
 *                                                                    *
 * Free Software Foundation           Voice:  +1-617-542-5942         *
 * 51 Franklin Street, Fifth Floor    Fax:    +1-617-542-2652         *
 * Boston, MA  02110-1301,  USA       gnu@gnu.org                     *
\*********************************************************************/



#ifndef GNUCASH_CALENDAR_GREGORIAN_LIB_H
#define GNUCASH_CALENDAR_GREGORIAN_LIB_H

#include "calendar-lib.h"

static const int gregorian_month_length[2][13] =
    {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

static const int gregorian_days_in_months[2][14] =
    {
        {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
        {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366}
    };

CalendarLib *gregorian_calendar_inti (void);

void gregorian_calendar_destroy (CalendarLib *);

static glong calc_days (guint year, guint mm, guint dd);

static guint day_of_week (guint year, guint mm, guint dd);

static glong dates_difference (guint year1, guint mm1, guint dd1,
                               guint year2, guint mm2, guint dd2);

static guint weeks_in_year (guint year);

static gboolean week_of_year (guint *week, guint *year, guint mm, guint dd);

static glong year_to_days (guint year);

static gboolean check_date (guint year, guint mm, guint dd);

static gboolean leap (guint year);

static guint week_number (guint year, guint mm, guint dd);

static void compute_paint_days (const gint year, const gint month,
                                const gint g_day, gint week_start,
                                gint day[6][7], gint day_month[6][7]);

static void init_day_name (char *default_abbreviated_dayname[7]);

static void init_month_name (char *default_monthname[12]);

static gchar *paint_header_helper (const gint g_yy, const gint g_mm, const gint g_dd,
                                   gint *display_month);

static gint display_selected_day (const gint g_yy, const gint g_mm, const gint g_dd);

static void
invalidate_display_day_to_gregorian (const gint selected_year, const gint selected_month,
                                     const gint selected_day, gint *gregorian_year,
                                     gint *gregorian_month, gint *gregorian_day);

#endif //GNUCASH_CALENDAR_GREGORIAN_LIB_H