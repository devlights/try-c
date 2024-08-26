THIS_FILE    := $(CURDIR)/$(firstword $(MAKEFILE_LIST))
SRCDIR       := $(CURDIR)
DESTDIR      := $(CURDIR)
PROGRAM      := app
PROGRAM_PATH := $(DESTDIR)/$(PROGRAM)
SRCS         := $(shell find $(CURDIR) -name '*.c' -type f)
INCDIRS      += $(shell find $(CURDIR) -type f -name '*.h' -exec dirname {} \; | sort | uniq)
OBJS         := $(SRCS:%.c=%.o)
DEPS         := $(SRCS:%.c=%.d)
CC           ?= clang
CFLAGS       += -g -O0 -Wall -Wextra -Werror -std=c17
LDFLAGS      +=
LDLIBS       +=

debug:
	@echo SRCS=$(SRCS)
	@echo INCDIRS=$(INCDIRS)

all: run                            ## デフォルトタスク (run)

clean:                              ## 成果物をクリアします
	$(RM) $(OBJS) $(DEPS) $(PROGRAM_PATH) 

run: build                          ## 実行します
	@$(PROGRAM_PATH)

build: $(PROGRAM)                   ## 成果物をビルドします

help:                               ## ヘルプを表示します
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(THIS_FILE) | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'

# 依存関係ファイルを生成し読み込み
# (ヘッダファイルが変更された場合に、それに依存するファイルが再コンパイルされるようにするため)
# (1)
%.d: %.c
	$(CC) $(CFLAGS) -MM -MF $@ $<

# clean ターゲットが指定されていない場合のみ依存関係ファイルを include
# (2)
ifeq ($(filter clean,$(MAKECMDGOALS)),)
-include $(DEPS)
endif

# コンパイルステップ
# (1)
%.o: %.c %.d
	$(CC) $(CFLAGS) -c $< -o $@ $(addprefix -I,$(INCDIRS))

# (2)
$(OBJS): $(SRCS)

# (3)
$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(PROGRAM_PATH) $(OBJS) $(LDLIBS)

.PHONY: all build clean run help