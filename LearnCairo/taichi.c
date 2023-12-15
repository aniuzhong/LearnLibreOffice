#include <cairo/cairo.h>

#define SIZE (640)
#define CX (SIZE / 2)
#define CY (SIZE / 2)
#define R (SIZE / 2)
#define ANGLE(ang) (ang * 3.1415926 / 180.0)

int main()
{
    cairo_surface_t* surface;
    cairo_t* cr;

    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, SIZE + 1, SIZE + 1);
    cr = cairo_create(surface);

    cairo_set_line_width(cr, 2.0);
    cairo_set_source_rgba(cr, 0, 0, 0, 1);
    cairo_arc(cr, CX, CY, R, ANGLE(0), ANGLE(360));
    cairo_stroke(cr);

    cairo_set_source_rgba(cr, 0, 0, 0, 1);
    cairo_arc(cr, CX, CY, R, ANGLE(90), ANGLE(270));
    cairo_fill(cr);
    cairo_set_source_rgba(cr, 1, 1, 1, 1);
    cairo_arc(cr, CX, CY, R, ANGLE(-90), ANGLE(90));
    cairo_fill(cr);

    cairo_set_source_rgba(cr, 0, 0, 0, 1);
    cairo_arc(cr, CX, CY - R / 2, R / 2, ANGLE(-90), ANGLE(90));
    cairo_fill(cr);
    cairo_set_source_rgba(cr, 1, 1, 1, 1);
    cairo_arc(cr, CX, CY + R / 2, R / 2, ANGLE(90), ANGLE(270));
    cairo_fill(cr);

    cairo_set_source_rgba(cr, 1, 1, 1, 1);
    cairo_arc(cr, CX, CY - R / 2, R / 10, ANGLE(0), ANGLE(360));
    cairo_fill(cr);
    cairo_set_source_rgba(cr, 0, 0, 0, 1);
    cairo_arc(cr, CX, CY + R / 2, R / 10, ANGLE(0), ANGLE(360));
    cairo_fill(cr);

    cairo_surface_write_to_png(surface, "taichi.png");

    cairo_surface_destroy(surface);
    cairo_destroy(cr);
}