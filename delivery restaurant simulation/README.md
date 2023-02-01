Program a simple train station model using multithreading.
Three different trains with symbols A, B, C depart from three points of departure at different times. They all go to the same station and can reach it at different times.
Only one train can be in this target station at a time. The rest of the trains wait until the already occupied seat is free.
At the beginning of the program, the user sequentially enters for each train the travel time to the station (in seconds). After that, the trains begin their movement for a given amount of time. As soon as the train has arrived at the station, it waits for the user to send the depart command, which signals its departure from the station.
For all events (arrival at the station, waiting for a free seat, departure from the station), along with the symbol of the train, messages are displayed in the console.
The program ends when all three trains have arrived at the station.