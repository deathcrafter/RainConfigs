[Variables]
InfoScroll=0

[ActionScroll]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Repeat ScrollDown, 0, 20
ActionList2=Repeat ScrollUp, 0, 20

ScrollDown=[!SetVariable InfoScroll "(Clamp([#InfoScroll]+0.05, 0, 1))"][!UpdateMeterGroup InfoScroll][!Redraw]
ScrollUp=[!SetVariable InfoScroll "(Clamp([#InfoScroll]-0.05, 0, 1))"][!UpdateMeterGroup InfoScroll][!Redraw]

[Background]
Meter=Shape
X=(270*#Scale#)
Shape=Rectangle 0,0,(650*#Scale#),(600*#Scale#),(10*#Scale#) | StrokeWidth 0 | Fill Color 20,20,20
MouseScrollUpAction=[!CommandMeasure ActionScroll "Stop 1"][!CommandMeasure ActionScroll "Execute 2"]
MouseScrollDownAction=[!CommandMeasure ActionScroll "Stop 2"][!CommandMeasure ActionScroll "Execute 1"]
MouseActionCursor=0

[PreviewImageContainer]
Meter=Shape
X=(20*#Scale#)r
Y=(20*#Scale#)r
Shape=Rectangle 0,0,(610*#Scale#),(400*#Scale#),(5*#Scale#) | StrokeWidth 0 | Fill LinearGradient MyGradient
MyGradient=270 | 255,255,255,255;0.0 | 255,255,255,0;0.85

[PreviewImage]
Meter=Image
ImageName=[&Meta:GetData('preview')]
W=(610*#Scale#)
PreserveAspectRatio=1
Container=PreviewImageContainer
DynamicVariables=1
Group=MainPanel

[InfoContainer]
Meter=Shape
X=(20*#Scale# - [#InfoScroll]*20*#Scale#)r
Y=(300*#Scale# - [#InfoScroll]*280*#Scale#)
Shape=Rectangle 0,0,(570*#Scale#+#InfoScroll#*40*#Scale#), (600*#Scale#) | StrokeWidth 0
DynamicVariables=1
Group=InfoScroll

[InfoBackground]
Meter=Shape
Shape=Rectangle 0,0,(570*#Scale#+#InfoScroll#*40*#Scale#),(600*#Scale#),(4*#Scale#) | StrokeWidth 0 | Fill LinearGradient DarkGradient
DarkGradient=225 | 90,90,90;0.0 | 20,20,20;1.0
Container=InfoContainer
DynamicVariables=1
Group=InfoScroll

[ConfigName]
Meter=String
FontSize=20
FontFace=Cascadia Code
FontWeight=700
AntiALias=1
DynamicVariables=1
FontColor=FEFEFE
Text=[&Meta:GetData('name')]
X=(20*#Scale#)r
Y=(25*#Scale#)r
Container=InfoContainer
Group=InfoScroll
W=(530*#Scale#-[#InfoScroll]*200*#Scale#)
ClipString=1

[RootName]
Meter=String
FontSize=10
FontWeight=400
X=r
Y=(10*#Scale#)R
MeterStyle=ConfigName
Text=[&Meta:GetData('root')]

[Author]
Meter=String
FontSize=10
FontWeight=400
X=r
Y=(30*#Scale#)R
MeterStyle=ConfigName
Text=Author : [&Meta:GetData('author')]

[Version]
Meter=String
FontSize=10
FontWeight=400
X=r
Y=(10*#Scale#)R
MeterStyle=ConfigName
Text=Version : [&Meta:GetData('version')]

[License]
Meter=String
FontSize=10
FontWeight=400
X=r
Y=(10*#Scale#)R
MeterStyle=ConfigName
Text=License : [&Meta:GetData('license')]
W=(530*#Scale#+[#InfoScroll]*40*#Scale#)
ClipString=1

[InformationHeader]
Meter=String
FontSize=10
FontWeight=400
X=r
Y=(10*#Scale#)R
MeterStyle=ConfigName
Text=Information :

[ActualInfo]
Meter=String
FontSize=10
FontWeight=400
W=(515*#Scale#-[InformationHeader:W])
H=(4*[Dummy:H])
X=R
Y=r
MeterStyle=ConfigName
Text=[&Meta:GetData('information')]
ClipString=2
ClipStringW=(515*#Scale#-[InformationHeader:W])

[Dummy]
Meter=String
Text=LMAO
Meter=String
FontSize=10
FontFace=Cascadia Code
FontWeight=400
AntiAlias=1
FontColor=0,0,0,0

[ControlButtonsBg]
Meter=Shape
X=(680*#Scale#)
Y=(40*#Scale#)
Shape=Rectangle 0,0,(200*#Scale#),(40*#Scale#),(5*#Scale#) | StrokeWidth 0 | Fill Color 100,100,100

[Load]
Meter=Image
X=(15*#Scale#)r
Y=(5*#Scale#)r
W=(30*#Scale#)
H=(30*#Scale#)
ImageName=#@#Icons\Load[&Meta:GetActive()].png
DynamicVariables=1
LeftMouseUpAction=[!CommandMeasure Meta Toggle()]

[Refresh]
Meter=Image
X=(15*#Scale#)R
Y=r
MeterStyle=Load
ImageName=#@#Icons\Refresh
LeftMouseUpAction=[!CommandMeasure Meta Refresh()]

[Edit]
Meter=Image
X=(15*#Scale#)R
Y=r
MeterStyle=Load
ImageName=#@#Icons\Edit
LeftMouseUpAction=[!CommandMeasure Meta Edit()]

[Favorite]
Meter=Image
X=(15*#Scale#)R
Y=r
MeterStyle=Load
ImageName=#@#Icons\hearts
LeftMouseUpAction=[!CommandMeasure Meta SetFav()]