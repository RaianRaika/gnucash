//
// Created by amin on 11/10/16.
//

#ifndef GNUCASH_CALENDAR_JALALI_LIB_H_H
#define GNUCASH_CALENDAR_JALALI_LIB_H_H


#include "calendar-lib.h"

static const   int jalali_month_length[2][13] =
        {
                {0, 31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 29},
                {0, 31, 31, 31, 31, 31, 31, 30, 30, 30, 30, 30, 30}
        };

static const int jalali_days_in_months[2][14] =
        {
                {0, 0, 31 ,62 ,93 ,124 ,155 ,186 ,216 ,246 ,276 ,306 ,336 ,365},
                {0, 0, 31, 62, 93, 124, 155, 186, 216, 246, 276, 306, 336, 366}
        };


static const char *jalali_month_name[12] =
        {
                "فروردین", "اردیبهشت", "خرداد",
                "تیر", "مرداد", "شهریور",
                "مهر", "ابان", "اذر",
                "دی", "بهمن", "اسفند"
        };

static const char *jalali_day_name[7]=
        {
                "یک","دو","سه","چهار","پنج","جمعه","شنبه"
        };


CalendarLib *jalali_calendar_inti(void);
void jalali_calendar_destroy(CalendarLib * );


static  glong calc_days(guint year, guint mm, guint dd) ;

static guint day_of_week(guint year, guint mm, guint dd) ;

static glong dates_difference(guint year1, guint mm1, guint dd1, guint year2, guint mm2, guint dd2);

static guint weeks_in_year(guint year) ;

static gboolean week_of_year(guint *week, guint *year, guint mm, guint dd) ;

static glong year_to_days(guint year) ;

static gboolean check_date(guint year, guint mm, guint dd) ;

static gboolean leap(guint year) ;

static guint week_number(guint year, guint mm, guint dd) ;

static void  compute_paint_days(const gint year,const gint month,const gint g_day,gint week_start,
                                gint day[6][7],gint day_month[6][7]);

static void init_day_name(char *default_abbreviated_dayname[7]);

static void init_month_name(char *default_monthname[12]);

static gchar * paint_header_helper(const gint g_yy , const gint g_mm,const gint g_dd,gint * display_month);

static gint display_selected_day(const gint g_yy,const gint g_mm,const gint g_dd);

static void invalidate_display_day_to_gregorian(const gint selected_year, const gint selected_month
        ,const gint selected_day,gint * gregorian_year,gint * gregorian_month,gint * gregorian_day);
#endif //GNUCASH_CALENDAR_JALALI_LIB_H_H
