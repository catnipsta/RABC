# RABC
RABC - Random Ass Beat Creator, for creating randomly generated beats in an instant.
RABC is a tool written in C for Linux (but should work on other UNIX systems) which utilizes SoX to generating beats randomly.
RABC does not use any AI to generate its beats, just randomness at its peak. Although it is extremely random, you do have the
choice of selecting its random seed, tempo (notes/beats per second), how many times it plays the beat, the beat's length, the
range of musical notes, and of course the destination/output file.

## INSTALL (SoX must be installed)
1. Clone the repository & cd into it  
```
git clone https://github.com/CatPeep/RABC.git && cd RABC
```  
  
2. Compile (gcc must be installed)  
```
make
```  
  
3. Install (Run as root)  
```
make install
```  
  
## RUNNING
```rabc [option] [argument]``` 

## FULL DOCUMENTATION
```man rabc```
