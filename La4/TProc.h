#ifndef TPROC_H
#define TPROC_H

class TProc {
private:
    int ActiveJob;

public:
    TProc();
    bool IsActive() const;
    void SetActiveJob(int job);
    void ProcessJob();
};

#endif 