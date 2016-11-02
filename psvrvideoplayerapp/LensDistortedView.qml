import QtQuick 2.0

ShaderEffect {
    property Item source
    property real curvature: 0.95
    property real ratio: height / width

    fragmentShader: "
        const float PI = 3.1415926535;

        uniform lowp float ratio;
        uniform lowp float curvature;

        varying mediump vec2 qt_TexCoord0;
        uniform lowp sampler2D source;
        uniform lowp float qt_Opacity;

        void main() {
            vec2 uv = qt_TexCoord0;
            vec2 xy = (2.0 * uv - 1.0) * vec2(1.0, ratio);

            float d = length(xy);

            if (d < (2.0 - curvature)) {
                d = length(xy * curvature);
                float z = sqrt(1.0 - d * d);
                float r = atan(d, z) / PI;
                float phi = atan(xy.y, xy.x);

                uv = vec2(cos(phi), sin(phi)) * r + 0.5;
            }

            gl_FragColor = texture2D(source, uv) * step(d, 2.0 - curvature);
        }"
}
