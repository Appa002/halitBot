cd build

cmake .. -G"Unix Makefiles"
make MyBot
..\halite.exe -d "240 160" ".\MyBot.exe" ".\MyBotOld.exe"
