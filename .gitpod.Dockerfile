FROM gitpod/workspace-full

RUN wget http://libcello.org/static/libCello-2.1.0.tar.gz \
    && tar -C Cello -zxf libCello-2.1.0.tar.gz

RUN cd Cello && make check && make && make install