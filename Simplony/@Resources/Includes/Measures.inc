
; © 2020 by xxenium


[WEATHER.COMSuperParent]
Measure=WebParser
URL=#URL#
UpdateRate=600
Flags=Resync | NoCookies
UserAgent=Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:77.0) Gecko/20100101 Firefox/77.0
DecodeCharacterReference=1
LogSubstringErrors=0
RegExp=(?siU)^(.*)$
StringIndex=1
FinishAction=[!EnableMeasureGroup Parents]


; ========================================
;                 LOCATION
; ========================================

[MeasureLocation]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#Location#
LogSubstringErrors=0

[MeasureAdminDistrictCode]
Measure=WebParser
Url=[MeasureLocation]
StringIndex=4
Substitute="null":"",'"':"","\":""
DecodeCodePoints=1

[MeasureCity]
Measure=WebParser
Url=[MeasureLocation]
StringIndex=7
Substitute="null":"",'"':"","\":""
DecodeCodePoints=1



; ========================================
;             CURRENT WEATHER
; ========================================


[MeasureCurrentObservations]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#CurrentObservations#
LogSubstringErrors=0
FinishAction=[!EnableMeasureGroup Time]

[MeasureIcon]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=1

[MeasurePressure]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=2

[MeasureHumidity]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=5

[MeasureTemperature]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=6

[MeasureFeelsLike]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=8

[MeasureUpdate]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=11
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1"

[MeasureUpdateTimeFormat12H]
Measure=Time
DynamicVariables=1
TimeStamp=[MeasureUpdate]
TimeStampFormat=%H:%S
Format=%#I:%S %p
Substitute="AM":"am","PM":"pm"
Group=Time
Disabled=1

[MeasureVisibility]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=12

[MeasureWindDirection]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=13
DecodeCodePoints=1

[MeasureWindSpeed]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=15
Substitute="\u002F":"/"

[MeasureCondition]
Measure=WebParser
Url=[MeasureCurrentObservations]
StringIndex=16
Substitute="\u002F":"/"
DecodeCodePoints=1

[MeasureUpdateTimeZone]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#UpdateTimeZone#
LogSubstringErrors=0

[MeasureUpdateTimeZoneAbbrev]
Measure=WebParser
Url=[MeasureUpdateTimeZone]
StringIndex=1



; ========================================
;              4 DAY FORECAST
; ========================================



;============= SUN ==================


[MeasureSun]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastSUN#
LogSubstringErrors=0

[MeasureSunrise]
Measure=WebParser
Url=[MeasureSun]
StringIndex=1
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1","":"[MeasureSunriseNext]"
DynamicVariables=1

[MeasureSunriseNext]
Measure=WebParser
Url=[MeasureSun]
StringIndex=2
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1"

[MeasureSunset]
Measure=WebParser
Url=[MeasureSun]
StringIndex=3
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1","":"[MeasureSunsetNext]"
DynamicVariables=1

[MeasureSunsetNext]
Measure=WebParser
Url=[MeasureSun]
StringIndex=4
RegExpSubstitute=1
Substitute="^.*T(.*):.*$":"\1"

[MeasureSunriseTimeFormat12H]
Measure=Time
TimeStamp=[MeasureSunrise]
TimeStampFormat=%H:%S
Format=%#I:%S %p
Substitute="AM":"am","PM":"pm"
DynamicVariables=1
Group=Time
Disabled=1

[MeasureSunsetTimeFormat12H]
Measure=Time
TimeStamp=[MeasureSunset]
TimeStampFormat=%H:%S
Format=%#I:%S %p
Substitute="AM":"am","PM":"pm"
DynamicVariables=1
Group=Time
Disabled=1


;============= TEMP MAX ==============


[MeasureDailyForecastTempMax]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastTempMax#
LogSubstringErrors=0

[MeasureTempMax1]
Measure=WebParser
Url=[MeasureDailyForecastTempMax]
StringIndex=1
Substitute="[":"","null":"---"

[MeasureTempMax2]
Measure=WebParser
Url=[MeasureDailyForecastTempMax]
StringIndex=2

[MeasureTempMax3]
Measure=WebParser
Url=[MeasureDailyForecastTempMax]
StringIndex=3

[MeasureTempMax4]
Measure=WebParser
Url=[MeasureDailyForecastTempMax]
StringIndex=4


;============== TEMP MIN ==============


[MeasureDailyForecastTempMin]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastTempMin#
LogSubstringErrors=0

[MeasureTempMin1]
Measure=WebParser
Url=[MeasureDailyForecastTempMin]
StringIndex=1
Substitute="[":""

[MeasureTempMin2]
Measure=WebParser
Url=[MeasureDailyForecastTempMin]
StringIndex=2

[MeasureTempMin3]
Measure=WebParser
Url=[MeasureDailyForecastTempMin]
StringIndex=3

[MeasureTempMin4]
Measure=WebParser
Url=[MeasureDailyForecastTempMin]
StringIndex=4


;============= DAYS ==================


[MeasureDailyForecastDate]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastDate#
LogSubstringErrors=0

[MeasureDate1]
Measure=WebParser
Url=[MeasureDailyForecastDate]
StringIndex=1
RegExpSubstitute=1
Substitute="^(.*)T.*$":"\1"

[MeasureDay1]
Measure=Time
TimeStamp=[MeasureDate1]
TimeStampFormat=%Y-%m-%d
Format=%a
FormatLocale=#Language#
DynamicVariables=1
Group=Time
Disabled=1

[MeasureDate2]
Measure=WebParser
Url=[MeasureDailyForecastDate]
StringIndex=2
RegExpSubstitute=1
Substitute="^(.*)T.*$":"\1"

[MeasureDay2]
Measure=Time
TimeStamp=[MeasureDate2]
TimeStampFormat=%Y-%m-%d
Format=%a
FormatLocale=#Language#
DynamicVariables=1
Group=Time
Disabled=1

[MeasureDate3]
Measure=WebParser
Url=[MeasureDailyForecastDate]
StringIndex=3
RegExpSubstitute=1
Substitute="^(.*)T.*$":"\1"

[MeasureDay3]
Measure=Time
TimeStamp=[MeasureDate3]
TimeStampFormat=%Y-%m-%d
Format=%a
FormatLocale=#Language#
DynamicVariables=1
Group=Time
Disabled=1

[MeasureDate4]
Measure=WebParser
Url=[MeasureDailyForecastDate]
StringIndex=4
RegExpSubstitute=1
Substitute="^(.*)T.*$":"\1"

[MeasureDay4]
Measure=Time
TimeStamp=[MeasureDate4]
TimeStampFormat=%Y-%m-%d
Format=%a
FormatLocale=#Language#
DynamicVariables=1
Group=Time
Disabled=1


;============= DAY PART ===============


[MeasureDailyForecastDayPart]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastDayPart#
LogSubstringErrors=0

[MeasureDayPartDay1]
Measure=WebParser
Url=[MeasureDailyForecastDayPart]
StringIndex=1
Substitute='"':"","[":"","null":"[MeasureDayPartNight1]","\":""
DynamicVariables=1
DecodeCodePoints=1

[MeasureDayPartNight1]
Measure=WebParser
Url=[MeasureDailyForecastDayPart]
StringIndex=2
DecodeCodePoints=1



;========= DAILY ICON CODES ===========


[MeasureDailyForecastIcon]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastIconCode#
LogSubstringErrors=0

[MeasureDailyIconDay1]
Measure=WebParser
Url=[MeasureDailyForecastIcon]
StringIndex=1
Substitute="[":"","null":"[MeasureDailyIconNight1]"
DynamicVariables=1

[MeasureDailyIconNight1]
Measure=WebParser
Url=[MeasureDailyForecastIcon]
StringIndex=2

[MeasureDailyIconDay2]
Measure=WebParser
Url=[MeasureDailyForecastIcon]
StringIndex=3

[MeasureDailyIconDay3]
Measure=WebParser
Url=[MeasureDailyForecastIcon]
StringIndex=5

[MeasureDailyIconDay4]
Measure=WebParser
Url=[MeasureDailyForecastIcon]
StringIndex=7


;===== DAILY PRECIPITATION CHANCE ======


[MeasureDailyForecastPrecip]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastPrecip#
LogSubstringErrors=0

[MeasureDailyPrecipDay1]
Measure=WebParser
Url=[MeasureDailyForecastPrecip]
StringIndex=1
Substitute="[":"","null":"[MeasureDailyPrecipNight1]"
DynamicVariables=1

[MeasureDailyPrecipNight1]
Measure=WebParser
Url=[MeasureDailyForecastPrecip]
StringIndex=2

[MeasureDailyPrecipDay2]
Measure=WebParser
Url=[MeasureDailyForecastPrecip]
StringIndex=3

[MeasureDailyPrecipDay3]
Measure=WebParser
Url=[MeasureDailyForecastPrecip]
StringIndex=5

[MeasureDailyPrecipDay4]
Measure=WebParser
Url=[MeasureDailyForecastPrecip]
StringIndex=7


;========= DAILY CONDITIONS ===========


[MeasureDailyForecastCond]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#DailyForecastCondition#
LogSubstringErrors=0

[MeasureDailyCondDay1]
Measure=WebParser
Url=[MeasureDailyForecastCond]
StringIndex=1
Substitute='"':"","\u002F":"/","[":"","null":"[MeasureDailyCondNight1]","\":""
DynamicVariables=1
DecodeCodePoints=1

[MeasureDailyCondNight1]
Measure=WebParser
Url=[MeasureDailyForecastCond]
StringIndex=2
Substitute="\u002F":"/"
DecodeCodePoints=1

[MeasureDailyCondDay2]
Measure=WebParser
Url=[MeasureDailyForecastCond]
StringIndex=3
Substitute="\u002F":"/"
DecodeCodePoints=1

[MeasureDailyCondDay3]
Measure=WebParser
Url=[MeasureDailyForecastCond]
StringIndex=5
Substitute="\u002F":"/"
DecodeCodePoints=1

[MeasureDailyCondDay4]
Measure=WebParser
Url=[MeasureDailyForecastCond]
StringIndex=7
Substitute="\u002F":"/"
DecodeCodePoints=1


; ========================================
;         WEATHER PARAMETERS LABELS
; ========================================


[MeasureWeatherParametersLabels]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#WeatherParametersLabels#
LogSubstringErrors=0

[MeasureFeelsLikeLabels]
Measure=WebParser
Url=[MeasureWeatherParametersLabels]
StringIndex=1
DecodeCodePoints=1

[MeasureWindLabels]
Measure=WebParser
Url=[MeasureWeatherParametersLabels]
StringIndex=3
DecodeCodePoints=1

[MeasureHumidityLabels]
Measure=WebParser
Url=[MeasureWeatherParametersLabels]
StringIndex=4
DecodeCodePoints=1

[MeasurePressureLabels]
Measure=WebParser
Url=[MeasureWeatherParametersLabels]
StringIndex=6
DecodeCodePoints=1

[MeasureVisibilityLabels]
Measure=WebParser
Url=[MeasureWeatherParametersLabels]
StringIndex=8
DecodeCodePoints=1


; ========================================
;          WEATHER PARAMETERS UNITS
; ========================================


[MeasureWeatherParametersUnits]
Measure=WebParser
Group=Parents
URL=[WEATHER.COMSuperParent]
Disabled=1
StringIndex=1
RegExp=#WeatherParametersUnits#
LogSubstringErrors=0

[MeasureMph]
Measure=WebParser
Url=[MeasureWeatherParametersUnits]
StringIndex=1
Substitute="\u002F":"/"
DecodeCodePoints=1

[MeasureKmh]
Measure=WebParser
Url=[MeasureWeatherParametersUnits]
StringIndex=2
Substitute="\u002F":"/"
DecodeCodePoints=1

[MeasureIn]
Measure=WebParser
Url=[MeasureWeatherParametersUnits]
StringIndex=3
DecodeCodePoints=1

[MeasureMb]
Measure=WebParser
Url=[MeasureWeatherParametersUnits]
StringIndex=4
DecodeCodePoints=1

[MeasureMile]
Measure=WebParser
Url=[MeasureWeatherParametersUnits]
StringIndex=5
DecodeCodePoints=1

[MeasureKm]
Measure=WebParser
Url=[MeasureWeatherParametersUnits]
StringIndex=6
DecodeCodePoints=1



; © 2020 by xxenium



















































