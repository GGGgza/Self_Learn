# Lux2EV100: math.log2(Lux/pi)

# Calculate EV100 based on aperture and shutter speed
## math.log2(aperture**2)/(1/shutter speed)

# Calculate aperture based on EV100 and shutter speed
## math.sqrt((math.pow(2,EV100))*(1/shutter speed))

# Calculate shutter speed based on EV100 and aperture
## 1/((aperture**2)/(math.pow(2,EV100)))

### aperture = n = 18.2
### shutter speed = t = 120 
### EV100 = e = 15.28
import math

calculateMode = ['Lux2EV100 = 0', 'calculate EV100 = 1','Calculate aperture = 2','Calculate shutter = 3']

for a in calculateMode:
    print(a)

s = int(input('Please enter Calculate Mode For Exprose:'))

match s:
    case 0:
        print('you will use Lux2EV100 Mode')
        l = float(input('Please enter lux value:'))
        print(math.log2(l/3.1415))
    case 1:
        print('you will use EV100 Mode')
        n = float(input('Please enter aperture value:'))
        t = float(input('Please enter shutter speed value:'))
        print(math.log2((n**2)/(1/t)))
    case 2:
         print('you will use Aperture Mode')
         ev = float(input('Please enter EV100 value:'))
         t = float(input('Please enter shutter speed value:'))
         print(math.sqrt((math.pow(2,ev))*(1/t)))
    case 3:
         print('you will use Shutter Speed Mode')
         n = float(input('Please enter Aperture value:'))
         ev = float(input('Please enter EV100 value:'))
         print(1/((n**2)/(math.pow(2,ev))))
    case _:
        print('???')