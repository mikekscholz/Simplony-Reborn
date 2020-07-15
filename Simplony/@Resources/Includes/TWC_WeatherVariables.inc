; © 2019 by Xxenium
; Code portions borrowed from JSMorley

; Modified by Eclectic Tech Jun 9, 2020 :: Combined variables to work as an @include file for TWC weather data V3 retrieval

; ################# ONE-TIME SETUP INSTRUCTIONS #############################

; Getting and setting your LocationCode can be done one of a couple of ways.
; 
; Go to https://weather.com/
; Search for your city by name.
; Use the long number at the end of the resulting URL, for example:
; https://weather.com/weather/today/l/d6ddc64611fafe9e42246c9121cca4035cc4a4558e28cf0c6e0982a7ef837329
; The LocationCode would be d6ddc64611fafe9e42246c9121cca4035cc4a4558e28cf0c6e0982a7ef837329
; Copy and enter that as the value for LocationCode below.
;
; Alternatively, in the USA, you can simply use your ZipCode as the LocationCode.
; The weather.com CountryRegion codes (e.g.; USNY0996) will also work as the LocationCode.
; NOTE: Imperial/Metric values displayed are determined based on the language selected; set the UnitsTemp accordingly to 'F' or 'C'.

; If another language or unit(s) of measures are desired, simply go to https://weather.com/
; Using the controls at the top of the page, set your country, language, and units of measure as desired.
; Copy and enter the LangLoc from the resulting URL, and the long number at the end as the LocationCode.
; Change UnitsTemp to either F or C to match what is displayed on the weather wbsite.

; For example, French would be LangLoc=fr-FR and UnitsTemp=C

; Note that simply changing from imperial F to metric C units of measure while keeping the 
; langage as English can be done by using en-GB as the LangLoc and C as the UnitsTemp.
 
[Variables]
SIMPLONYCOLOR=255,255,255
LocationCode=ce209a70441cdd49b7737f9f153cad8f5ede97f3ded0e4dfd85f176501692326

; Change to F or C to display in current temp and to control the 'UNITS' values to match Imperial(F) or Metric(C) measurements.
UnitsTemp=F

; MPH or KMH
SpeedUnit=MPH
; IN or MB
PressureUnit=IN
; MILE or KM
VisibilityUnit=MILE

; You can set your language-location for TWC here
; For English and Celsius use en-CA outside of United Kingdom
LangLoc=en-US

; Set language here to translate entire skin
; Available Options: Catalan, Chinese, Croatian, Czech, Danish, Dutch, English, French, German, Greek, Hungarian, Italian, Latvian, Polish, Portuguese, Romanian, Russian, Serbian, Spanish, Swedish, Turkish, Ukrainian.
Language=English

DateFormat=%h %#d

; Sunrise/Sunset display: 12H or 24H
TimeFormat=24H

; Translations
; Change the short day names to your language
ShortDayNames="Monday":"Mon","Tuesday":"Tue","Wednesday":"Wed","Thursday":"Thu","Friday":"Fri","Saturday":"Sat","Sunday":"Sun"

; Change the terms on the right of the equal sign to your language
FeelsLike=Feels Like
Wind=Wind
Visibility=Visibility
Barometer=Barometer
Humidity=Humidity
Dewpoint=Dewpoint
Gusts=Gusts
Trend=Trend
MoonPhase=Current Moon Phase
UpdatedAt=Updated: 

RetrievingWeather=Retrieving Location...
RetrievingConditions=Retrieving Conditions...
RetrievingForecasts=Retrieving Forecasts...
RetrievingDays=Retrieving Days...
RetrievingMoonData=Retrieving Moon Data...
RetrievingMinMaxTemps=Retrieving Min/Max Temps...
RetrievingDayNight=Retrieving Day/Night...
RetrievingIcons=Retrieving Icons...
RetrievingDetails=Retrieving Details...
RetrievingPrecip=Retrieving Precipitation...
RetrievingDaily=Retrieving Daily Conditions...

; =====================================
; Don't change anything below here.
; =====================================

WeatherUpdateRate=6000

URL=https://weather.com/#LangLoc#/weather/today/l/#LocationCode#
URL2=https://weather.com/#LangLoc#/forecast/allergy/l/#LocationCode#

Days=7
Hours=2

Location=(?siU)"getSunV3LocationPointUrlConfig":.*{"location":{"latitude":(.*),"longitude":(.*),.*,"adminDistrict":(.*),"adminDistrictCode":(.*),.*,"country":(.*),"countryCode":(.*),.*,"displayName":(.*),.*}

CurrentObservations=(?siU)"getSunV3CurrentObservationsUrlConfig":.*{"cloudCeiling":.*,"cloudCoverPhrase":".*","dayOfWeek":".*","dayOrNight":".*","expirationTimeUtc":.*,"iconCode":(.*),"iconCodeExtend":.*,"obsQualifierCode":.*,"obsQualifierSeverity":.*,"precip1Hour":.*,"precip6Hour":.*,"precip24Hour":.*,"pressureAltimeter":(.*),"pressureChange":(.*),"pressureMeanSeaLevel":.*"pressureTendencyCode":.*,"pressureTendencyTrend":"(.*)","relativeHumidity":(.*),"snow1Hour":.*,"snow6Hour":.*,"snow24Hour":.*,"sunriseTimeLocal":"(.*)","sunriseTimeUtc":.*"sunsetTimeLocal":"(.*)","sunsetTimeUtc":.*"temperature":(.*),"temperatureChange24Hour":.*,"temperatureDewPoint":(.*),"temperatureFeelsLike":(.*),"temperatureHeatIndex":.*"temperatureMax24Hour":.*"temperatureMaxSince7Am":.*"temperatureMin24Hour":.*"temperatureWindChill":.*"uvDescription":"(.*)","uvIndex":(.*),"validTimeLocal":"(.*)","validTimeUtc":.*"visibility":(.*),"windDirection":.*"windDirectionCardinal":"(.*)","windGust":(.*),"windSpeed":(.*),"wxPhraseLong":"(.*)","wxPhraseMedium":.*,"wxPhraseShort":.*}

UpdateTimeZone=(?siU)"getSunV3CurrentDateTimeByGeocodeUrlConfig":{"geocode:.*":{.*,"data":{"dateTime":".*","ianaTimeZone":".*","timeZoneAbbreviation":"(.*)"}

DailyForecastDayOfWeek=(?siU)"getSunV3DailyForecastUrlConfig":.*{"dayOfWeek":.*"(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)"

DailyForecastMoon=(?siU)"getSunV3DailyForecastUrlConfig":.*{.*"moonPhase":."(.*)",.*,"moonPhaseCode":.*"(.*)",.*"moonriseTimeLocal":.*"(.*)","(.*)",.*"moonsetTimeLocal":.*"(.*)","(.*)"

DailyForecastTempMax=(?siU)"getSunV3DailyForecastUrlConfig":.*{.*"temperatureMax":(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),.*

DailyForecastTempMin=(?siU)"getSunV3DailyForecastUrlConfig":.*{.*"temperatureMin":(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),.*

DailyForecastDate=(?siU)"getSunV3DailyForecastUrlConfig":.*{.*"validTimeLocal":.*"(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)"

DailyForecastDayPart=(?siU)"getSunV3DailyForecastUrlConfig":.*{.*"daypartName":(.*),"(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)"

DailyForecastIconCode=(?siU)"getSunV3DailyForecastUrlConfig":.*{.*"iconCode":(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),.*

DailyForecastDetails=(?siU)"getSunV3DailyForecastUrlConfig":.*{.*"iconCode":.*"narrative":(.*),"(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)"

DailyForecastPrecip=(?siU)"getSunV3DailyForecastUrlConfig":.*{.*"precipChance":(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),.*

DailyForecastCondition=(?siU)"getSunV3DailyForecastUrlConfig":.*{.*"wxPhraseLong":(.*),"(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)"

HourlyForecastIconCode=(?siU)"getSunV3HourlyForecastUrlConfig":.*{.*"iconCode":(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),.*

HourlyForecastPrecip=(?siU)"getSunV3HourlyForecastUrlConfig":.*{.*"precipChance":(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),.*

HourlyForecastTemp=(?siU)"getSunV3HourlyForecastUrlConfig":.*{.*"temperature":(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),.*

HourlyForecastHour=(?siU)"getSunV3HourlyForecastUrlConfig":.*{.*"validTimeLocal":.*"(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)"

HourlyForecastCondition=(?siU)"getSunV3HourlyForecastUrlConfig":.*{.*"wxPhraseLong":(.*),"(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)"

WeatherAlert=(?siU)"getSunWeatherAlertHeadlinesUrlConfig":.*{.*,"alerts":.*(?(?=.*{"detailKey").*:".*",.*,"eventDescription":"(.*)","severityCode":(.*),"severity":"(.*)",.*,"headlineText":"(.*)",.*}).*(?(?=.*{"detailKey").*:".*",.*,"eventDescription":"(.*)","severityCode":(.*),"severity":"(.*)",.*,"headlineText":"(.*)",.*}).*(?(?=.*{"detailKey").*:".*",.*,"eventDescription":"(.*)","severityCode":(.*),"severity":"(.*)",.*,"headlineText":"(.*)",.*}).*(?(?=.*{"detailKey").*:".*",.*,"eventDescription":"(.*)","severityCode":(.*),"severity":"(.*)",.*,"headlineText":"(.*)",.*}).*(?(?=.*{"detailKey").*:".*",.*,"eventDescription":"(.*)","severityCode":(.*),"severity":"(.*)",.*,"headlineText":"(.*)",.*}).*(?(?=.*{"detailKey").*:".*",.*,"eventDescription":"(.*)","severityCode":(.*),"severity":"(.*)",.*,"headlineText":"(.*)",.*}).*(?(?=.*{"detailKey").*:".*",.*,"eventDescription":"(.*)","severityCode":(.*),"severity":"(.*)",.*,"headlineText":"(.*)",.*}).*(?(?=.*{"detailKey").*:".*",.*,"eventDescription":"(.*)","severityCode":(.*),"severity":"(.*)",.*,"headlineText":"(.*)",.*}).*

PollenForecastDayPart=(?siU)"getSunIndexPollenDaypartUrlConfig":.*{.*"daypartName":(.*),"(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)"

PollenForecastGrassPollenIndex=(?siU)"getSunIndexPollenDaypartUrlConfig":.*{.*"grassPollenIndex":(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),.*}

PollenForecastGrassPollenCategory=(?siU)"getSunIndexPollenDaypartUrlConfig":.*{.*"grassPollenCategory":.*"(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)".*

PollenForecastTreePollenIndex=(?siU)"getSunIndexPollenDaypartUrlConfig":.*{.*"treePollenIndex":(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),.*

PollenForecastTreePollenCategory=(?siU)"getSunIndexPollenDaypartUrlConfig":.*{.*"treePollenCategory":.*"(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)".*

PollenForecastRagweedPollenIndex=(?siU)"getSunIndexPollenDaypartUrlConfig":.*{.*"ragweedPollenIndex":(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),.*

PollenForecastRagweedPollenCategory=(?siU)"getSunIndexPollenDaypartUrlConfig":.*{.*"ragweedPollenCategory":.*"(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)","(.*)".*

AirQuality=(?siU)"getSunV3GlobalAirQualityUrlConfig":.*{.*"airQualityIndex":(.*),"airQualityCategory":"(.*)",.*,"primaryPollutant":"(.*)"

PollutantNO2=(?siU)"getSunV3GlobalAirQualityUrlConfig":.*{.*"pollutants":{"NO2":{"name":"(.*)","phrase":"(.*)","amount":(.*),"unit":"(.*)","category":"(.*)",.*}

PollutantO3=(?siU)"getSunV3GlobalAirQualityUrlConfig":.*{.*"pollutants":{.*"O3":{"name":"(.*)","phrase":"(.*)","amount":(.*),"unit":"(.*)","category":"(.*)",.*}

PollutantSO2=(?siU)"getSunV3GlobalAirQualityUrlConfig":.*{.*"pollutants":{.*"SO2":{"name":"(.*)","phrase":"(.*)","amount":(.*),"unit":"(.*)","category":"(.*)",.*}

PollutantPM2.5=(?siU)"getSunV3GlobalAirQualityUrlConfig":.*{.*"pollutants":{.*"PM2.5":{"name":"(.*)","phrase":"(.*)","amount":(.*),"unit":"(.*)","category":"(.*)",.*}

PollutantPM10=(?siU)"getSunV3GlobalAirQualityUrlConfig":.*{.*"pollutants":{.*"PM10":{"name":"(.*)","phrase":"(.*)","amount":(.*),"unit":"(.*)","category":"(.*)",.*}

PollutantCO=(?siU)"getSunV3GlobalAirQualityUrlConfig":.*{.*"pollutants":{.*"CO":{"name":"(.*)","phrase":"(.*)","amount":(.*),"unit":"(.*)","category":"(.*)",.*}

AirQualitySensitiveGroupMessage=(?siU)"getSunV3GlobalAirQualityUrlConfig":.*{.*"messages":{"Sensitive Group":{"title":"(.*)","text":"(.*)"}

AirQualityGeneralMessage=(?siU)"getSunV3GlobalAirQualityUrlConfig":.*{.*"messages":.*"General":{"title":"(.*)","text":"(.*)"}

WeatherParametersLabels=(?siU)"wxu-today-details":{.*,"feelsLike":"(.*)","highLow":"(.*)","wind":"(.*)","humidity":"(.*)","dewPoint":"(.*)","pressure":"(.*)","uvIndex":"(.*)","visibility":"(.*)","moonPhase":"(.*)".*}

AirQualityLabels=(?siU)"wxu-air-quality":{"airQuality":"(.*)".*}

PollenLabels=(?siU)"wxu-allergy-pollen":{.*,"grassPollen":"(.*)","ragweedPollen":"(.*)","treePollen":"(.*)",.*}

WeatherParametersUnits=(?siU)"wxu-general":{"noData":".*","mph":"(.*)","km.*h":"(.*)","in":"(.*)","mb":"(.*)","mi":"(.*)","km":"(.*)",.*}




; © 2020 by xxenium









