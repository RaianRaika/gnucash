//
// Created by amin on 11/10/16.
//

#ifndef GNUCASH_CALENDAR_LIB_H
#define GNUCASH_CALENDAR_LIB_H
#include "config.h"
#include <glib.h>

enum {
    MONTH_PREV,
    MONTH_CURRENT,
    MONTH_NEXT
};
typedef struct CalendarLib {

        guint **month_length;
    guint **days_in_months;



     glong (*calc_days)(guint year, guint mm, guint dd);

     guint (*day_of_week)(guint year, guint mm, guint dd);

     glong (*dates_difference)(guint year1, guint mm1, guint dd1,
                                   guint year2, guint mm2, guint dd2);

     guint (*weeks_in_year)(guint year);

     gboolean (*week_of_year)(guint *week, guint *year, guint mm, guint dd);
     glong (*year_to_days)(guint year);
     gboolean (*check_date)(guint year, guint mm, guint dd);
     gboolean (*leap)(guint year);
     guint (*week_number)(guint year, guint mm, guint dd);

    /**
     *
     * @param year
     * @param month
     * @param g_day
     * @param week_start
     * @param day
     * @param day_month
     */
    void (*compute_paint_days)(const gint year,const gint month,const gint g_day,gint week_start,
                                                  gint day[6][7],gint day_month[6][7]);

    /**
     *
     * @param default_abbreviated_dayname
     */
    void (*init_day_name)(char *default_abbreviated_dayname[7]);
    /**
     *
     * @param default_monthname
     */
    void (*init_month_name)(char *default_monthname[12]);


   /**
    *
    * @param g_yy
    * @param g_mm
    * @param g_dd
    * @param display_month
    * @return gchar * charecter of years
    */
    gchar * (*paint_header_helper)(const gint g_yy , const gint g_mm,const gint g_dd,gint * display_month);


    /**
     *
     * @param g_yy
     * @param g_mm
     * @param g_dd
     * @return  gint currect selected day !
     */
    gint (*display_selected_day)(const gint g_yy,const gint g_mm,const gint g_dd);



    void (*invalidate_display_day_to_gregorian)(const gint selected_year, const gint selected_month
            ,const gint selected_day,gint * gregorian_year,gint * gregorian_month,gint * gregorian_day);



} CalendarLib;



#endif //GNUCASH_CALENDAR_LIB_H
