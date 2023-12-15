#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>

int main()
{
    cairo_surface_t* surface;
    cairo_t* cr;
    cairo_text_extents_t extents;

    // Prepare drawing area
    int width = 200;
    int height = 120;

    surface = cairo_pdf_surface_create("hello.pdf", width, height);
    cr = cairo_create(surface);

    // Drawing code goes here
    cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);
    cairo_select_font_face(cr, "Georgia", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size(cr, 20);
    cairo_text_extents(cr, "helloworld", &extents);
    cairo_move_to(cr, width / 2 - extents.width / 2 - extents.x_bearing,
                  height / 2 - extents.height / 2 - extents.y_bearing);
    cairo_show_text(cr, "helloworld");

    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return 0;
}