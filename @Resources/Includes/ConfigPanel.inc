[StringStyle]
FontFace=Cascadia Code
FontWeight=400
FontSize=(12*#Scale#)
FontColor=255,255,255
Padding=5,0,5,0
SolidColor=0,0,0,1
X=R
AntiAlias=1
DynamicVariables=1
Container=ConfigPanelContainer

[IconStyle]
Y=(10*#Scale#)R
H=(20*#Scale#)
W=(20*#Scale#)
DynamicVariables=1
Container=ConfigPanelContainer
Group=Icons | Scroll

[IndicatorStyle]
X=(12*#Scale#)r
Y=(10*#Scale#)r
H=(12*#Scale#)
W=(12*#Scale#)
DynamicVariables=1
Container=ConfigPanelContainer

[Icon]
Meter=Image
Container=ConfigPanelContainer

[Icon1]
Meter=Image
X=([&RainConfigs:GetProp("(1+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(1+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(1+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(1+[#Index])", 'lmb')]
[Indicator1]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(1+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(1+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[1]
Meter=String
Y=[Icon1:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(1+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(1+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(1+[#Index])", 'lmb')]

[Icon2]
Meter=Image
X=([&RainConfigs:GetProp("(2+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(2+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(2+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(2+[#Index])", 'lmb')]
[Indicator2]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(2+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(2+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[2]
Meter=String
Y=[Icon2:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(2+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(2+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(2+[#Index])", 'lmb')]

[Icon3]
Meter=Image
X=([&RainConfigs:GetProp("(3+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(3+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(3+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(3+[#Index])", 'lmb')]
[Indicator3]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(3+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(3+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[3]
Meter=String
Y=[Icon3:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(3+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(3+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(3+[#Index])", 'lmb')]

[Icon4]
Meter=Image
X=([&RainConfigs:GetProp("(4+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(4+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(4+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(4+[#Index])", 'lmb')]
[Indicator4]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(4+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(4+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[4]
Meter=String
Y=[Icon4:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(4+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(4+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(4+[#Index])", 'lmb')]

[Icon5]
Meter=Image
X=([&RainConfigs:GetProp("(5+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(5+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(5+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(5+[#Index])", 'lmb')]
[Indicator5]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(5+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(5+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[5]
Meter=String
Y=[Icon5:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(5+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(5+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(5+[#Index])", 'lmb')]

[Icon6]
Meter=Image
X=([&RainConfigs:GetProp("(6+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(6+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(6+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(6+[#Index])", 'lmb')]
[Indicator6]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(6+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(6+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[6]
Meter=String
Y=[Icon6:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(6+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(6+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(6+[#Index])", 'lmb')]

[Icon7]
Meter=Image
X=([&RainConfigs:GetProp("(7+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(7+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(7+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(7+[#Index])", 'lmb')]
[Indicator7]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(7+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(7+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[7]
Meter=String
Y=[Icon7:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(7+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(7+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(7+[#Index])", 'lmb')]

[Icon8]
Meter=Image
X=([&RainConfigs:GetProp("(8+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(8+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(8+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(8+[#Index])", 'lmb')]
[Indicator8]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(8+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(8+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[8]
Meter=String
Y=[Icon8:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(8+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(8+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(8+[#Index])", 'lmb')]

[Icon9]
Meter=Image
X=([&RainConfigs:GetProp("(9+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(9+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(9+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(9+[#Index])", 'lmb')]
[Indicator9]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(9+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(9+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[9]
Meter=String
Y=[Icon9:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(9+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(9+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(9+[#Index])", 'lmb')]

[Icon10]
Meter=Image
X=([&RainConfigs:GetProp("(10+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(10+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(10+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(10+[#Index])", 'lmb')]
[Indicator10]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(10+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(10+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[10]
Meter=String
Y=[Icon10:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(10+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(10+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(10+[#Index])", 'lmb')]

[Icon11]
Meter=Image
X=([&RainConfigs:GetProp("(11+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(11+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(11+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(11+[#Index])", 'lmb')]
[Indicator11]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(11+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(11+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[11]
Meter=String
Y=[Icon11:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(11+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(11+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(11+[#Index])", 'lmb')]

[Icon12]
Meter=Image
X=([&RainConfigs:GetProp("(12+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(12+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(12+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(12+[#Index])", 'lmb')]
[Indicator12]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(12+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(12+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[12]
Meter=String
Y=[Icon12:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(12+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(12+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(12+[#Index])", 'lmb')]

[Icon13]
Meter=Image
X=([&RainConfigs:GetProp("(13+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(13+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(13+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(13+[#Index])", 'lmb')]
[Indicator13]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(13+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(13+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[13]
Meter=String
Y=[Icon13:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(13+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(13+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(13+[#Index])", 'lmb')]

[Icon14]
Meter=Image
X=([&RainConfigs:GetProp("(14+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(14+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(14+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(14+[#Index])", 'lmb')]
[Indicator14]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(14+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(14+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[14]
Meter=String
Y=[Icon14:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(14+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(14+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(14+[#Index])", 'lmb')]

[Icon15]
Meter=Image
X=([&RainConfigs:GetProp("(15+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(15+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(15+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(15+[#Index])", 'lmb')]
[Indicator15]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(15+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(15+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[15]
Meter=String
Y=[Icon15:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(15+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(15+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(15+[#Index])", 'lmb')]

[Icon16]
Meter=Image
X=([&RainConfigs:GetProp("(16+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(16+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(16+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(16+[#Index])", 'lmb')]
[Indicator16]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(16+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(16+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[16]
Meter=String
Y=[Icon16:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(16+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(16+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(16+[#Index])", 'lmb')]

[Icon17]
Meter=Image
X=([&RainConfigs:GetProp("(17+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(17+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(17+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(17+[#Index])", 'lmb')]
[Indicator17]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(17+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(17+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[17]
Meter=String
Y=[Icon17:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(17+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(17+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(17+[#Index])", 'lmb')]

[Icon18]
Meter=Image
X=([&RainConfigs:GetProp("(18+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(18+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(18+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(18+[#Index])", 'lmb')]
[Indicator18]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(18+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(18+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[18]
Meter=String
Y=[Icon18:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(18+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(18+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(18+[#Index])", 'lmb')]

[Icon19]
Meter=Image
X=([&RainConfigs:GetProp("(19+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(19+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(19+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(19+[#Index])", 'lmb')]
[Indicator19]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(19+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(19+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[19]
Meter=String
Y=[Icon19:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(19+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(19+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(19+[#Index])", 'lmb')]

[Icon20]
Meter=Image
X=([&RainConfigs:GetProp("(20+[#Index])", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("(20+[#Index])", 'image')]
MeterStyle=IconStyle
Hidden=[&RainConfigs:GetProp("(20+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(20+[#Index])", 'lmb')]
[Indicator20]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(20+[#Index])", 'activecolor')]
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color [&RainConfigs:GetProp("(20+[#Index])", 'containsactivecolor')]
MeterStyle=IndicatorStyle
[20]
Meter=String
Y=[Icon20:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("(20+[#Index])", 'text')]
Hidden=[&RainConfigs:GetProp("(20+[#Index])", 'hidden')]
LeftMouseUpAction=[&RainConfigs:GetProp("(20+[#Index])", 'lmb')]

[IconDummy]
Meter=Image
ImageAlpha=0
X=([&RainConfigs:GetProp("dummy", 'x')]+[#HorizontalScrollHori]*(250*#Scale#-[&RainConfigs:GetWidth()]))
ImageName=#@#Icons\[&RainConfigs:GetProp("dummy", 'image')]
MeterStyle=IconStyle
Hidden=0
Group=Dummy
[IndicatorDummy]
Meter=Shape
Shape=Ellipse (6*#Scale#), (6*#Scale#), (6*#Scale#) | StrokeWidth 0 | Fill Color 0,0,0,0
Shape2=Ellipse (6*#Scale#), (6*#Scale#), (3*#Scale#) | StrokeWidth 0 | Fill Color 0,0,0,0
MeterStyle=IndicatorStyle
Group=Dummy
[Dummy]
Meter=String
FontColor=0,0,0,0
Y=[IconDummy:Y]
MeterStyle=StringStyle
Text=[&RainConfigs:GetProp("dummy", 'text')]
Hidden=0
Group=Dummy