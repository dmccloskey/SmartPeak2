// TODO: Add copyright

#pragma once
#include <SmartPeak/core/Filenames.h>
#include <SmartPeak/core/RawDataHandler.h>
#include <SmartPeak/core/RawDataProcessor.h>
#include <SmartPeak/core/SequenceHandler.h>
#include <SmartPeak/core/SequenceSegmentHandler.h>
#include <SmartPeak/core/SequenceSegmentProcessor.h>
#include <vector>
#include <memory>

namespace SmartPeak
{
  class SequenceProcessor
  {
public:
    SequenceProcessor()                                    = delete;
    ~SequenceProcessor()                                   = delete;
    SequenceProcessor(const SequenceProcessor&)            = delete;
    SequenceProcessor& operator=(const SequenceProcessor&) = delete;
    SequenceProcessor(SequenceProcessor&&)                 = delete;
    SequenceProcessor& operator=(SequenceProcessor&&)      = delete;

    /**
      Create a new sequence from files or wizard.

      @param[in,out] sequenceHandler_IO Sequence handler
      @param[in] filenames Pathnames to load
      @param[in] delimiter String delimiter of the imported file
      @param[in] checkConsistency Check consistency of data contained in files
      @param[in] verbose_I Verbosity
    */
    static void createSequence(
      SequenceHandler& sequenceHandler_IO,
      const Filenames& filenames,
      const std::string& delimiter = ",",
      const bool checkConsistency = true,
      const bool verbose_I = false
    );

    /**
      Apply a processing workflow to all injections in a sequence.

      @param[in,out] sequenceHandler_IO Sequence handler
      @param[in] filenames Mapping from injection names to pathnames
      @param[in] injection_names Injections to select from the sequence
      @param[in] raw_data_processing_methods_I Events to process
      @param[in] verbose_I Verbosity
    */
    static void processSequence(
      SequenceHandler& sequenceHandler_IO,
      const std::map<std::string, Filenames>& filenames,
      const std::set<std::string>& injection_names = {},
      const std::vector<std::shared_ptr<RawDataProcessor>>&
        raw_data_processing_methods_I = {},
      const bool verbose_I = false
    );

    /**
      Apply a processing workflow to all injections in a sequence segment.

      @param[in,out] sequenceHandler_IO Sequence handler
      @param[in] filenames Mapping from sequence groups names to pathnames
      @param[in] sequence_segment_names Sequence groups to select from the sequence
      @param[in] sequence_segment_processing_methods_I Events to process
      @param[in] verbose_I Verbosity
    */
    static void processSequenceSegments(
      SequenceHandler& sequenceHandler_IO,
      const std::map<std::string, Filenames>& filenames,
      const std::set<std::string>& sequence_segment_names = {},
      const std::vector<std::shared_ptr<SequenceSegmentProcessor>>&
        sequence_segment_processing_methods_I = {},
      const bool verbose_I = false
    );
  };
}
