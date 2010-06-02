///-----------------------------------------------
// Copyright 2010 Wellcome Trust Sanger Institute
// Written by Jared Simpson (js18@sanger.ac.uk)
// Released under the GPL
//-----------------------------------------------
//
// ErrorCorrectProcess - Wrapper to perform error correction
// for a sequence work item
//
#ifndef CORRECTROCESS_H
#define CORRECTPROCESS_H

#include "Util.h"
#include "OverlapAlgorithm.h"
#include "SequenceProcessFramework.h"
#include "SequenceWorkItem.h"

enum ECFlag
{
    ECF_NOTCORRECTED,
    ECF_CORRECTED,
    ECF_AMBIGIOUS,
    ECF_DUPLICATE
};

class ErrorCorrectResult
{
    DNAString correctSequence;
    ECFlag flag;
};

//
class ErrorCorrectProcess
{
    public:
        ErrorCorrectProcess(const OverlapAlgorithm* pOverlapper, 
                            int minOverlap);

        ~ErrorCorrectProcess();

        ErrorCorrectResult process(const SequenceWorkItem& item);
    
    private:
        OverlapBlockList m_blockList;
        const OverlapAlgorithm* m_pOverlapper;
        const int m_minOverlap;
};

// Write the results from the overlap step to an ASQG file
class ErrorCorrectPostProcess
{
    public:
        ErrorCorrectPostProcess(std::ostream* pWriter);
        void process(const SequenceWorkItem& item, const ErrorCorrectResult& result);

    private:
        std::ostream* m_pWriter;
};

#endif
