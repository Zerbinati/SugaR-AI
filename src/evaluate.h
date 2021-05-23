/*
  SugaR, a UCI chess playing engine derived from Stockfish
  Copyright (C) 2004-2021 The Stockfish developers (see AUTHORS file)

  SugaR is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  SugaR is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef EVALUATE_H_INCLUDED
#define EVALUATE_H_INCLUDED

#include <string>
#include <optional>

#include "types.h"

namespace Stockfish {

class Position;

namespace Eval {

  void init(bool verify);
  std::string trace(const Position& pos);
  Value evaluate(const Position& pos);

  extern bool useNNUE;
  extern bool useClassical;
  extern std::string eval_file_loaded;

  // The default net name MUST follow the format nn-[SHA256 first 12 digits].nnue
  // for the build process (profile-build and fishtest) to work. Do not change the
  // name of the macro, as it is used in the Makefile.
  #define EvalFileDefaultName   "nn-7756374aaed3.nnue"

  namespace NNUE {

    Value evaluate(const Position& pos, bool adjusted = false);
    bool load_eval(std::string name, std::istream& stream);
    bool save_eval(std::ostream& stream);
    void init();
    void export_net(const std::optional<std::string>& filename);
    void verify();

  } // namespace NNUE

} // namespace Eval

} // namespace Stockfish

#endif // #ifndef EVALUATE_H_INCLUDED
