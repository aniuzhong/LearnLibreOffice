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

