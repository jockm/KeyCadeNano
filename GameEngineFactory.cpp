// Copyright (c) 2018 Jock Murphy. jock@jockmurphy.com
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "GameEngineFactory.h"

#include "GameEngines/Chip8/Chip8.h"
#include "GameEngines/EmbedVM/EmbedVMEngine.h"
#include "GameEngines/UBasic/UBasicGameEngine.h"

GameEngineFactory::GameEngineFactory() {
	// Nothing

}

GameEngineFactory::~GameEngineFactory() {
	// Nothing
}


NanoGameEngine *GameEngineFactory::getEngine(GameType type)
{
	NanoGameEngine *ret = NULL;

	switch(type) {
		case GT_CHIP8:
			ret = (NanoGameEngine *)new Chip8();
			break;

		case GT_EMBEDVM:
			ret = (NanoGameEngine *)new EmbedVMEngine();
			break;

		case GT_UBASIC:
			ret = (NanoGameEngine *)new UBasicGameEngine();
			break;

		default:
			break;
	}

	return ret;
}
