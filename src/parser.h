#ifndef ADA_PARSER_H
#define ADA_PARSER_H

#include <optional>

namespace ada {

  class url_parser {

  public:
    url_parser(std::string_view input, std::optional<ada::url> optional_base_url, std::optional<ada::encoding_type> encoding, std::optional<ada::state> state);
    ada::url get_url();

  private:
    void parse_state();

    std::string_view input{};
    std::string buffer{};
    bool at_sign_seen{};
    bool inside_brackets{};
    bool password_token_seen{};

    const char* pointer;

    ada::encoding_type encoding{ada::encoding_type::UTF8};
    ada::state state{SCHEME_START};
    std::optional<ada::state> state_override;

    ada::url url;
    std::optional<ada::url> base_url;
  }; // class url_parser

}

#endif // ADA_PARSER_H
