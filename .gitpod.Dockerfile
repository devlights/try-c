FROM gitpod/workspace-full

RUN wget http://libcello.org/static/libCello-2.1.0.tar.gz \
    && tar -zxf libCello-2.1.0.tar.gz

RUN cd libCello-2.1.0 \
    && make check \
    && make \
    && sudo make install