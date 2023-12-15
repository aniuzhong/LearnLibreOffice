sd/source/ui/slideshow/slideshowimpl.cxx:1756

``` C++
void SlideshowImpl::startUpdateTimer()
{
    double fUpdate = 0.0;
    if (!xShow->update(fUpdate))
        fUpdate = -1.0;
    
    // ...

    maUpdateTimer.SetTimeout(static_cast<sal_uLong>(fUpdate * 1000.0));
    maUpdateTimer.Start();

    // ...
}
```

Changing `fUpdate` to `1` make slide show every 1000 ms


canvas/source/cairo/cairo_spritecanvashelper.cxx:147

``` C++
bool SpriteCanvasHelper::updateScreen( const ::basegfx::B2IRange&, bool bUpdateAll, bool& io_bSurfaceDirty)
{
    // ...

    cairo_paint(pWindowCairo.get());
    auto new = std::chrono::system_clock::now();
    auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto value = now_ms.time_since_epoch().count();
    std::string name1 = "/tmp/" + std::to_string(value) + ".png";
    cairo_surface_write_to_png(pCompositingSurface->getCairoSurface().get(), name1.c_str());

    // ...
}
```

Dump png when showing slides
