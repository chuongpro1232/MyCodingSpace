/*
 * // Approach: there are two types of events: arrival and departure
 * // When we scan the events from soonest to latest,
 * // if we encounter an arrival event => increase the gates required
 * // if we encounter a departure event => decrease the gates required
 * // during this process: need to maintain the maximum gates at all points in
 * time
 * 
 * arrival = [N]
 * departure = [N]
 * 
 * for i = 0 to N-1
 * arrival[i] = planes[i].arrival
 * departure[i] = planes[i].departure
 * // => complexity: O(N)
 * 
 * sort(arrival)
 * sort(departure)
 * // => complexity: O(N*lg(N))
 * 
 * // compare the next arrival event to the next departure event
 * // to see which one occurs first, then proceed to the next event of the same
 * type
 * // repeat this process until there is no more event to compare
 * // Implementation: use two-pointers technique
 * 
 * arrivalIdx = departureIdx = 0
 * gates = maxGates = 0
 * while arrivalIdx < N && departureIdx < N
 * if arrival[arrivalIdx] < departure[departureIdx]
 * gates++
 * arrivalIdx++
 * else
 * gates--
 * departureIdx++
 * maxGates = max(maxGates, gates)
 * // in each iteration, either arrivalIdx or departureIdx increases by one
 * // when one of them reaches N, the while loop stops
 * // the total number of increasement cannot be greater than 2*N
 * // => complexity: O(N)
 * 
 * return maxGates
 * 
 * // Final complexity: O(N) + O(N*lg(N)) + O(N) = O(N*lg(N))
 * 
 */
