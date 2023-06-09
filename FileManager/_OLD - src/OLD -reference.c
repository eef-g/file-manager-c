/*
#include "../headers/Partition.h"
#include "../headers/utility.h"

#pragma region ReservedSectors Functions

ReservedSectors* ReservedSectors_new(FILE* file, int* offset, int isFAT32)
{
    ReservedSectors* self = (ReservedSectors*) malloc(sizeof(ReservedSectors));
    ReservedSectors_init(self, file, offset, isFAT32);
    return self;
}

void ReservedSectors_init(ReservedSectors* self, FILE* file, int* offset, int isFAT32)
{
    self->boot = BootSector_new(file, offset);
    if(isFAT32 == 1)
        self->fsInfo = FSInfo_new(file, offset);
    else
        self->fsInfo = NULL;
}

void ReservedSectors_print(ReservedSectors* self)
{
    BootSector_print(self->boot);
    if(self->fsInfo != NULL)
        FSInfo_print(self->fsInfo);
}

void ReservedSectors_destroy(ReservedSectors* self)
{
    BootSector_destroy(self->boot);
    FSInfo_destroy(self->fsInfo);
    free(self);
}

BootSector* BootSector_new(FILE* file, int* offset)
{
    BootSector* self = (BootSector*) malloc(sizeof(BootSector));
    BootSector_init(self, file, offset);
    return self;
}

void BootSector_init(BootSector* self, FILE* file, int* offset)
{
    fpread(&self->bytesPerSector, 2, 1, offset, file);
    fread(&self->sectorsPerCluster, 1, 1, file);
    fread(&self->reservedSectors, 2, 1, file);
    fread(&self->fatCopies, 1, 1, file);
    fread(&self->rootEntries, 2, 1, file);
    fread(&self->totalSectors, 2, 1, file);
    fread(&self->mediaDescriptor, 1, 1, file);
    fread(&self->sectorsPerFAT, 2, 1, file);
    fread(&self->sectorsPerHead, 2, 1, file);
    fread(&self->headsPerCylinder, 2, 1, file);
    fread(&self->hiddenSectors, 4, 1, file);
    fread(&self->bigNumberofSectors, 4, 1, file);
    fread(&self->bigNumberSectorsPerFAT32, 4, 1, file);
    fread(&self->flags, 2, 1, file);
    fread(&self->version, 2, 1, file);
    fread(&self->rootCluster, 4, 1, file);
    fread(&self->fsInfoSector, 2, 1, file);
    fread(&self->backupBootSector, 2, 1, file);
    fread(&self->reserved, 12, 1, file);
}

void BootSector_print(BootSector* self)
{
    printf("-= Boot Sector Info =-\n");
    printf("Bytes per sector: 0x%X\n", self->bytesPerSector);
    printf("Sectors per cluster: 0x%X\n", self->sectorsPerCluster);
    printf("Reserved sectors: 0x%X\n", self->reservedSectors);
    printf("FAT copies: 0x%X\n", self->fatCopies);
    printf("Root entries: 0x%X\n", self->rootEntries);
    printf("Total sectors: 0x%X\n", self->totalSectors);
    printf("Media descriptor: 0x%X\n", self->mediaDescriptor);
    printf("Sectors per FAT: 0x%X\n", self->sectorsPerFAT);
    printf("Sectors per head: 0x%X\n", self->sectorsPerHead);
    printf("Heads per cylinder: 0x%X\n", self->headsPerCylinder);
    printf("Hidden sectors: 0x%X\n", self->hiddenSectors);
    printf("Big number of sectors: 0x%X\n", self->bigNumberofSectors);
    printf("Big number of sectors per FAT32: 0x%X\n", self->bigNumberSectorsPerFAT32);
    printf("Flags: 0x%X\n", self->flags);
    printf("Version: 0x%X\n", self->version);
    printf("Root cluster: 0x%X\n", self->rootCluster);
    printf("FS Info sector: 0x%X\n", self->fsInfoSector);
    printf("Backup boot sector: 0x%X\n", self->backupBootSector);
}

void BootSector_destroy(BootSector* self)
{
    free(self);
}

FSInfo* FSInfo_new(FILE* file, int* offset)
{
    FSInfo* self = (FSInfo*) malloc(sizeof(FSInfo));
    FSInfo_init(self, file, offset);
    return self;
}

void FSInfo_init(FSInfo* self, FILE* file, int* offset)
{
    fread(&self->signature, 4, 1, file);
    fread(&self->reserved, 480, 1, file);
    fread(&self->signature2, 4, 1, file);
    fread(&self->freeClusterCount, 4, 1, file);
    fread(&self->nextFreeCluster, 4, 1, file);
    fread(&self->reserved2, 12, 1, file);
    fread(&self->signature3, 4, 1, file);
}

void FSInfo_print(FSInfo* self)
{
    printf("\n-= FS Info =-\n");
    printf("Signature: 0x%X\n", self->signature);
    printf("Signature2: 0x%X\n", self->signature2);
    printf("Free cluster count: 0x%X\n", self->freeClusterCount);
    printf("Next free cluster: 0x%X\n", self->nextFreeCluster);
    printf("Signature3: 0x%X\n", self->signature3);
}

void FSInfo_destroy(FSInfo* self)
{
    free(self);
}

FTable* FTable_new(FILE* file)
{
  FTable* self = (FTable*)malloc(sizeof(FTable));
  FTable_init(self, file);
  return self;
}

void FTable_init(FTable* self, FILE* file)
{
  printf("FTable initialized\n");
}

void FTable_destroy(FTable* self)
{
  free(self); 
}

#pragma endregion



Partition* Partition_new(FILE* file, int* offset, int isFAT32)
{
    Partition* self = (Partition*) malloc(sizeof(Partition));
    Partition_init(self, file, offset, isFAT32);
    return self;
}

void Partition_init(Partition* self, FILE* file, int* offset, int isFAT32)
{
    self->reserved = ReservedSectors_new(file, offset, isFAT32);
    self->tables[0] = FTable_new(file);
    self->tables[1] = FTable_new(file);
}

void Partition_print(Partition* self)
{
    ReservedSectors_print(self->reserved);
}

*/