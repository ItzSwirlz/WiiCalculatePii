# WiiCalculatePii
Seeing how many digits of Pi a Wii can calculate (single core IBM PowerPC Broadway CPU) 

## Explanation
The Wii has a 32-bit IBM PowerPC CPU, clocked at 729 MHz, known as the [Broadway](https://wiibrew.org/wiki/Hardware/Broadway).

Pi has been calculated before using [WPCP](https://wiibrew.org/wiki/WPCP), using the "Taniver" (?) method. The wiki page says it only shows 15 digits, but it (at least attempts to) shows 50. The devs also said when math.h works, they would have more methods. To my knowledge, this is the farthest Pi has been calculated on a Wii.. as of 2010. It also does not log to a file, hiding more possible digits.

I'm pretty sure math.h works now, and even with or without what it contains, I'd prefer to see it all coded all by hand (or as much as possible). Also, the [Chudnovsky algorithm](https://en.wikipedia.org/wiki/Chudnovsky_algorithm) should be used (rapidly converges, not computer-memory intensive).

Obviously, this project is for fun, and whatever calculation comes out will be obsolete, not only because of the hardware, but also compared to the next world record calculation that results while the current calculation is ongoing.

## Other Transcendentals
- Euler's Number (e): I actually did write a program for this using the infinite series (1/n!), I might make a repo for it, or include it in this repo.
- Square root of 2 and others (√2): I haven't written anything in C, only in Python with string concatenation so I can use the eval() function until Python complains about too many nested parentheses (I'm not kidding). Until I have the.. expertise to write it in C (for the speed), I'm not doing anything any time soon.

## Contributing
PRs are appreciated! Just note that I do not want a GUI for the highest speed of calculation, other than printing the current calculation on the screen to show progress.

I'm also open to letting the user choose an algorithm/method to calculate Pi with.

You can also contribute to the leaderboard, if you have the patience to wait probably days or make more tweaks to the code (before you PR it, take the credit for the record). I also ask not to use Dolphin for actually using the program to calculate Pi. (Obviously, you should still use it when testing the code, but emulation != real hardware)

## Leaderboard
Rules: No Dolphin, show some photographic evidence (unless you really really want to, don't feel compelled to upload a full time-lapse), upload result text file

| Username | Method | Digits | Time | Evidence |
| -------- | ------ | ------ | ---- | -------- |