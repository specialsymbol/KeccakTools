/*
Tools for the Keccak sponge function family.
Authors: Guido Bertoni, Joan Daemen, Michaël Peeters and Gilles Van Assche

This code is hereby put in the public domain. It is given as is, 
without any guarantee.

For more information, feedback or questions, please refer to our website:
http://keccak.noekeon.org/
*/

#ifndef _KECCAKF25LUT_H_
#define _KECCAKF25LUT_H_

#include <vector>
#include "Keccak-f.h"
#include "Keccak-fParts.h"

using namespace std;

/**
  * Class implementing Keccak-<i>f</i>[25] using a look-up table (LUT).
  */
class KeccakF25LUT : public KeccakF {
public:
    /**
      * Attribute containing the lookup table for Keccak-<i>f</i>[25].
      * It is generated by generateLUT() or loaded from disk by retrieveLUT().
      */
    vector<SliceValue> LUT;
public:
    /**
      * The constructor, for which the width is fixed to 25. It generates a lookup table
      * for the Keccak-<i>f</i>[25] permutation with a given number of rounds.
      * When done, the lookup table is saved to disk.
      * If the lookup table exists on disk, it is retrieved instead of being generated.
      * See KeccakF() for more details.
      */
    KeccakF25LUT(unsigned int aNrRounds = 0);
protected:
    /**
      * Method that saves the lookup table to a file with extension '.LUT'.
      */
    void saveLUT() const;
    /**
      * Method that retrieves the lookup table from a file with extension '.LUT'.
      */
    bool retrieveLUT();
    /**
      * Method that generates the actual lookup table.
      */
    void generateLUT();
};

#endif
