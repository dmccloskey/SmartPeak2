#pragma once

#include <SmartPeak/core/AppStateProcessor.h> // TODO: maybe forward declaration could do it
#include <SmartPeak/core/Utilities.h>
#include <SmartPeak/ui/Widget.h>
#include <array>
#include <string>
#include <vector>
#include <boost/filesystem.hpp>

namespace fs = boost::filesystem;

namespace SmartPeak
{
  class FilePicker final : public Widget
  {
    std::array<std::vector<std::string>, 4> pathname_content_;
    std::string current_pathname_ = fs::current_path().root_path().string();
    std::string picked_pathname_;
    std::string title_            = "Pick a pathname";
    AppStateProcessor* processor_ = nullptr;

  public:
    bool        show_file_picker_ = false;

    FilePicker()
    {
      pathname_content_ = Utilities::getPathnameContent(current_pathname_);
    }

    void draw() override;

    std::string getPickedPathname() const;

    void setTitle(const std::string& title);

    void setProcessor(AppStateProcessor& processor);

    void runProcessor();

    void clearProcessor();
  };
}