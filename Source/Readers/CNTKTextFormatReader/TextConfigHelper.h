//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//

#pragma once

#include <string>
#include <vector>
#include "Config.h"
#include "Descriptors.h"

namespace Microsoft { namespace MSR { namespace CNTK {

// A helper class for text specific parameters.
// A simple wrapper around CNTK ConfigParameters.
class TextConfigHelper
{
public:
    explicit TextConfigHelper(const ConfigParameters& config);

    // Get all input streams that are specified in the configuration.
    const vector<StreamDescriptor>& GetStreams() const { return m_streams; }

    // Get full path to the input file.
    const wstring& GetFilePath() const { return m_filepath; }

    size_t GetRandomizationWindow() const { return m_randomizationWindow; }

    bool ShouldSkipSequenceIds() const { return m_skipSequenceIds; }

    unsigned int GetMaxAllowedErrors() const { return m_maxErrors; }

    unsigned int GetTraceLevel() const { return m_traceLevel; }

    size_t GetChunkSize() const { return m_chunkSizeBytes; }

    bool ShouldKeepDataInMemory() const { return m_keepDataInMemory; }

    bool IsInFrameMode() const { return m_frameMode; }

    bool useCategoryBasedSampling() const { return m_categoryBasedSampling; }

    size_t GetSamplerPerCategory() const { return m_samplePerCategory; }

    ElementType GetElementType() const { return m_elementType; }

    std::wstring GetCategoryInfoName() const { return m_categoryInfoName; }

    DISABLE_COPY_AND_MOVE(TextConfigHelper);

private:
    std::wstring m_filepath;
    std::vector<StreamDescriptor> m_streams;
    size_t m_randomizationWindow;
    ElementType m_elementType;
    bool m_skipSequenceIds;
    unsigned int m_maxErrors;
    unsigned int m_traceLevel;
    size_t m_chunkSizeBytes; // chunks size in bytes
    bool m_keepDataInMemory; // if true the whole dataset is kept in memory
    bool m_frameMode; // if true, the maximum expected sequence length in the dataset is one sample.
    bool m_categoryBasedSampling; // whether to conduct category based sampling.
    size_t m_samplePerCategory; // how many instances to sample from each category.
    std::wstring m_categoryInfoName; // the stream name for the label
};

} } }
