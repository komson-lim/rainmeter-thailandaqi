[Variables]
color = "255,255,255,255"
orange = "255,127,0,255"
red = "255,0,0,255"
blue = "92,203,250,255"
green = "124,240,89,255"
yellow = "255,255,0,255"
qualityText = Loading . . .
; Enter your ID below here
ID = 02t
[GetJSON]
Measure = WebParser
URL = http://air4thai.pcd.go.th/services/getNewAQI_JSON.php?stationID=#ID#
RegExp=(?siU)"stationID":"(.*)".*"nameEN":"(.*)".*"areaEN":"(.*)".*"date":"(.*)".*"time":"(.*)".*"PM25":.*"value":"(.*)".*"unit":"(.*)".*"PM10":.*"value":"(.*)".*"unit":"(.*)".*"O3":.*"value":"(.*)".*"unit":"(.*)".*"CO":.*"value":"(.*)".*"unit":"(.*)".*"NO2":.*"value":"(.*)".*"unit":"(.*)".*"SO2":.*"value":"(.*)".*"unit":"(.*)".*"AQI":.*"level":"(.*)".*"aqi":"(.*)"
UpdateRate = 600
FinishAction = [!Log "Retrieved AQI" "Notice"]
[MeasureID]
Measure = WebParser
URL = [GetJSON]
StringIndex = 1
[MeasureNameEN]
Measure = WebParser
URL = [GetJSON]
StringIndex = 2
[MeasureAreaEN]
Measure = WebParser
URL = [GetJSON]
StringIndex = 3
[MeasureDate]
Measure = WebParser
URL = [GetJSON]
StringIndex = 4
[MeasureTime]
Measure = WebParser
URL = [GetJSON]
StringIndex = 5
[MeasurePM25Value]
Measure = WebParser
URl = [GetJSON]
StringIndex = 6
[MeasurePM25Unit]
Measure = WebParser
URl = [GetJSON]
StringIndex = 7
[MeasurePM10Value]
Measure = WebParser
URl = [GetJSON]
StringIndex = 8
[MeasurePM10Unit]
Measure = WebParser
URl = [GetJSON]
StringIndex = 9
[MeasureO3Value]
Measure = WebParser
URl = [GetJSON]
StringIndex = 10
[MeasureO3Unit]
Measure = WebParser
URl = [GetJSON]
StringIndex = 11
[MeasureCOValue]
Measure = WebParser
URl = [GetJSON]
StringIndex = 12
[MeasureCOUnit]
Measure = WebParser
URl = [GetJSON]
StringIndex = 13
[MeasureNO2Value]
Measure = WebParser
URl = [GetJSON]
StringIndex = 14
[MeasureNO2Unit]
Measure = WebParser
URl = [GetJSON]
StringIndex = 15
[MeasureSO2Value]
Measure = WebParser
URl = [GetJSON]
StringIndex = 16
[MeasureSO2Unit]
Measure = WebParser
URl = [GetJSON]
StringIndex = 17
[MeasureAQILevel]
Measure = WebParser
URl = [GetJSON]
StringIndex = 18
[MeasureAQI]
Measure = WebParser
URl = [GetJSON]
StringIndex = 19
[MeasureLevel]
Measure = Calc
Formula = MeasureAQILevel
IfCondition = (MeasureLevel = 1)
IfTrueAction = [!SetVariable "color" "#blue#"][!SetVariable "qualityText" "Very Good"]
IfCondition2= (MeasureLevel = 2)
IfTrueAction2 = [!SetVariable "color" "#green#"][!SetVariable "qualityText" "Good"]
IfCondition3 = (MeasureLevel = 3)
IfTrueAction3 = [!SetVariable "color" "#yellow#"][!SetVariable "qualityText" "Moderate"]
IfCondition4 = (MeasureLevel = 4)
IfTrueAction4 = [!SetVariable "color" "#orange#"][!SetVariable "qualityText" "Unhealty for Sensitive Groups"]
IfCondition5 = (MeasureLevel = 5)
IfTrueAction5 = [!SetVariable "color" "#red#"][!SetVariable "qualityText" "Unhealty"]
DynamicVariables = 1
