/*
 Given the arrival and departure time of planes reaching a particular airport. You need to find the minimum number of gates required to accommodate the planes at any point in time.

For example:

P1 = {1:00, 1:10}

P2 = {1: 40, 3:00}

P3 = {1:50, 2:20}

P4 = {2:00, 2:30}

P5 = {2:15, 3:15}

P6 = {4:00, 6:00}

=> number of gates required = 4

What is the complexity of your algorithm? In this problem, N is the number of planes.

Approach: 2 types of events: arrival and departure
Scan the events from earliest to lastest
if encounter an arrival event, increase the gates required
if encounter a departure event, decrease the gates required
However, during process, keep track of the number of gates required at all points in time

arrival = [N]
departure =[N]

for i = 0 to N-1
    arrival[i] = planes[i].arrival
    departure[i] = planes[i].departure
sort(arrival)
sort(departure)
-> complexity: 0(N log N)

arrivalIdx = departureIdx = 0
gates = maxGates = 0
while arrivalIdx < N && departureIdx < N
    if arrival[arrivalIdx] < departure[departureIdx]
        gates++
        arrivalIdx++
    else
        gates--
        arrivalIdx++
    maxGates = max(gates,maxGates)

-> complexity: 0(N)

return maxGates
total complexity: 0(N) +0(N log N) + 0(N) = 0(N log N + 2N) = 0(N log N)
 */