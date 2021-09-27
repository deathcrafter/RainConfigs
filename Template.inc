[Icon$i]
Meter=Image
X=[&RainConfigs:GetProp("($i+[#Index])", 'x')]
ImageName=#@#Icons\[&RainConfigs:GetProp("($i+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("($i+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("($i+[#Index])", 'lmb')]
[Indicator$i]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("($i+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (4*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("($i+[#Index])", 'containsactivecolor')]
[$i]
Meter=String
Y=[Icon$($i):Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("($i+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("($i+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("($i+[#Index])", 'lmb')]