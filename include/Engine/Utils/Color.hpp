#pragma once

#include <cmath>
#include <algorithm>

namespace Util
{
    class Color
    {
    public:
        static float rgb2grayscale(float r, float g, float b)
        {
            r = r / 255.0;
            g = g / 255.0;
            b = b / 255.0;

            return (0.2126 * r) + (0.7152 * g) + (0.0722 * b);
        }

        static float *hsv2rgb(float hue, float sat, float val)
        {
            float r, g, b;
            float i, f, p, q, t;
            float *result = new float[3];

            if (val == 0)
            {
                r = 0;
                g = 0;
                b = 0;
            } else
            {
                hue /= 60;
                i = floor(hue);
                f = hue - i;
                p = val * (1 - sat);
                q = val * (1 - (sat * f));
                t = val * (1 - (sat * (1 - f)));
                if (i == 0)
                {
                    r = val;
                    g = t;
                    b = p;
                } else if (i == 1)
                {
                    r = q;
                    g = val;
                    b = p;
                } else if (i == 2)
                {
                    r = p;
                    g = val;
                    b = t;
                } else if (i == 3)
                {
                    r = p;
                    g = q;
                    b = val;
                } else if (i == 4)
                {
                    r = t;
                    g = p;
                    b = val;
                } else if (i == 5)
                {
                    r = val;
                    g = p;
                    b = q;
                }
            }

            result[0] = r;
            result[1] = g;
            result[2] = b;
            return result;
        }

        static float *rgb2hsv(float r, float g, float b)
        {
            float hue, sat, val;
            float x, f, i;
            float *result = new float[3];

            x = std::min(std::min(r, g), b);
            val = std::max(std::max(r, g), b);
            if (x == val)
            {
                hue = 0;
                sat = 0;
            } else
            {
                f = (r == x) ? g - b : ((g == x) ? b - r : r - g);
                i = (r == x) ? 3 : ((g == x) ? 5 : 1);
                hue = fmod((i - f / (val - x)) * 60, 360);
                sat = ((val - x) / val);
            }

            result[0] = hue;
            result[1] = sat;
            result[2] = val;
            return result;
        }
    };
}